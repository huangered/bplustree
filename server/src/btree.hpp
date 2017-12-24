//
//  btree.hpp
//  kkkk
//
//  Created by peter.huang on 21/11/2017.
//  Copyright © 2017 peter.huang. All rights reserved.
//

#ifndef btree_hpp
#define btree_hpp

#include <vector>

namespace linn {

#define DEGREE 4096

typedef bool tree_node_type;

const tree_node_type tree_node_leaf = true;
const tree_node_type tree_node_body = false;

template <class _RandomAccessIter, class T>
int index(const _RandomAccessIter begin, const _RandomAccessIter end,
          const T &key) {
  long low = 0, high = std::distance(begin, end);
  while (low != high) {
    int mid = (high + low) / 2;
    if (begin[mid] < key) {
      low = mid + 1;
    } else if (begin[mid] == key) {
      low = high = mid;
      break;
    } else {
      high = mid;
    }
  }
  return low;
}

class btree_node_base {
protected:
  tree_node_type _leaf;

public:
  btree_node_base(tree_node_type leaf) : _leaf(leaf) {}
};

template <class V> struct btreedata {
  V value;
  btreedata *pre;
  btreedata *next;
  btreedata(V value) : value(value), pre(nullptr), next(nullptr) {}
};

template <class V>
class btree_iterator
    : public std::iterator<std::bidirectional_iterator_tag, btreedata<V> *,
                           btreedata<V>, const btreedata<V> *, V> {
private:
  btreedata<V> *data;

public:
  explicit btree_iterator(btreedata<V> *data) : data(data) {}

  btree_iterator<V> &operator++() {
    data = data->next;
    return *this;
  }

  btree_iterator<V> operator++(int) {
    btree_iterator retval = *this;
    ++(*this);
    return retval;
  }

  bool operator==(btree_iterator<V> other) const { return data == other.data; }
  bool operator!=(btree_iterator<V> other) const { return data != other.data; }

  V operator*() const { return data->value; }
};

template <class K, class V> class btreenode : public btree_node_base {
  typedef btreedata<V> _btree_data_type;

public:
  std::vector<K> _keys;
  std::vector<btreenode<K, V> *> _nodes;
  std::vector<_btree_data_type *> _data;

public:
  btreenode(tree_node_type leaf) : linn::btree_node_base(leaf) {}
  ~btreenode() {}
  btreenode(const btreenode &n) = delete;
  btreenode &operator=(const btreenode &other) = delete;

  K getMiddleElemKey() const { return _keys[DEGREE / 2]; }

  void insert(const K &key, const V &value) {
    if (_leaf == tree_node_leaf) {
      _insert_leaf(key, value);
    } else {
      _insert_body(key, value);
    }
  }
  void remove(const K &key) {}

  _btree_data_type *find(const K &key) {
    if (_leaf == tree_node_leaf) {
      auto iter = std::find(_keys.begin(), _keys.end(), key);
      if (iter != _keys.end()) {
        return _data[std::distance(_keys.begin(), iter)];
      } else {
        return nullptr;
      }
    } else {
      auto upperNode = std::upper_bound(_keys.begin(), _keys.end(), key);
      int distance = std::distance(_keys.begin(), upperNode);
      return _nodes[distance]->find(key);
    }
  }
  btreenode *split() {
    btreenode<K, V> *newNode = new btreenode<K, V>(_leaf);
    int mid = DEGREE / 2;
    auto midNode = _keys.begin() + mid;
    newNode->_keys.assign(midNode, _keys.end());
    _keys.erase(midNode, _keys.end());
    if (_leaf == tree_node_body) {
      auto c = _nodes.begin() + mid;
      newNode->_nodes.assign(c, _nodes.end());
      _nodes.erase(c, _nodes.end());
    } else {
      auto c = _data.begin() + mid;
      newNode->_data.assign(c, _data.end());
      _data.erase(c, _data.end());
    }
    return newNode;
  }

  _btree_data_type *first() const {
    if (_leaf == tree_node_leaf) {
      return *(_data.begin());
    } else {
      return (*(_nodes.begin()))->first();
    }
  }

private:
  void _insert_leaf(const K &key, const V &value) {
    auto up = std::upper_bound(_keys.begin(), _keys.end(), key);
    // int distance = std::distance(_keys.begin(), up);
    int distance = index(_keys.begin(), _keys.end(), key);
    _keys.insert(up, key);
    _btree_data_type *newLeafNode = new _btree_data_type(value);
    if (!_data.empty()) {
      _btree_data_type *first;
      if (distance == _data.size()) {
        first = _data[distance - 1]->next;
      } else {
        first = _data[distance];
      }
      newLeafNode->next = first;
      newLeafNode->pre = first->pre;
      newLeafNode->pre->next = newLeafNode;
      first->pre = newLeafNode;
    }
    _data.insert(_data.begin() + distance, newLeafNode);
    return;
  }

  void _insert_body(const K &key, const V &value) {
    int index = -1;
    for (int i = 0; i < _keys.size(); i++) {
      if (key < _keys[i]) {
        index = i;
        break;
      }
    }
    if (index == -1) {
      index = _keys.size();
    }
    if (_nodes[index]->_keys.size() == DEGREE) {
      int mid = _nodes[index]->getMiddleElemKey();
      btreenode<K, V> *newSplitNode = _nodes[index]->split();

      _keys.insert(_keys.begin() + index, mid);
      _nodes.insert(_nodes.begin() + index + 1, newSplitNode);
      if (key < mid) {
        _nodes[index]->insert(key, value);
      } else {
        newSplitNode->insert(key, value);
      }
    } else {
      _nodes[index]->insert(key, value);
    }
  }
};
template <class K, class V> class tree {

  typedef btreenode<K, V> _btree_node_type;
  typedef btreedata<V> _btree_data_type;

  _btree_node_type *root;
  _btree_data_type *tail;

  int _size;

public:
  typedef btree_iterator<V> iterator;

  tree() : root(nullptr), tail(nullptr), _size(0) {}
  ~tree() {
    if (root != nullptr) {
      delete root;
    }
  }

  void insert(const K &key, const V &value) {
    if (root == nullptr) {
      _btree_node_type *node = new _btree_node_type(tree_node_leaf);
      node->insert(key, value);
      root = node;

      tail = new btreedata<V>(0);
      tail->pre = node->first();
      tail->next = node->first();
      node->first()->next = tail;
      node->first()->pre = tail;
    } else {
      if (root->_keys.size() == DEGREE) {
        V mid = root->getMiddleElemKey();
        _btree_node_type *split_one = root->split();

        _btree_node_type *newRoot = new _btree_node_type(tree_node_body);
        newRoot->_keys.push_back(mid);
        newRoot->_nodes.push_back(root);
        newRoot->_nodes.push_back(split_one);
        root = newRoot;
      }
      root->insert(key, value);
    }
    ++_size;
  }
  void remove(const K &key) {
    if (root == nullptr) {
    } else {
      root->remove(key);
      --_size;
    }
  }

  iterator find(const K &key) {
    if (root == nullptr) {
      return iterator(tail);
    } else {
      return iterator(root->find(key));
    }
  }
  iterator begin() const { return iterator(tail->next); }
  iterator end() const { return iterator(tail); }

  int size() const { return _size; }
};

} // namespace linn
#endif /* btree_hpp */
