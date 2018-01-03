build:
	clang-format -i **/*.cpp
	clang-format -i **/*.hpp

	xcodebuild -workspace root.xcworkspace -scheme all

clean:
	rm -rf build