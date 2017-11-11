//
//  server.hpp
//  test
//
//  Created by huang on 2017/12/9.
//  Copyright © 2017年 huang. All rights reserved.
//

#ifndef server_hpp
#define server_hpp
namespace yih {
typedef void (*handler)(void *);

struct ThreadArg {
  int _fd;
  handler _h;
};

class Server {
private:
  const static int MSG_LEN;
  int _port;
  handler _h;
  handler _error_handler;

  static void *run(void *arg);

public:
  Server(int p, handler h) : _port(p), _h(h) {}

  void start();
};
} // namespace yih
#endif /* server_hpp */
