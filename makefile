build:
	find . -name *.*pp |xargs clang-format -i

	xcodebuild -workspace root.xcworkspace -scheme all

clean:
	rm -rf build