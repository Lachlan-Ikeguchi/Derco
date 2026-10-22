config:
	cmake -B build -S .

build: config
	cmake --build build

clean:
	rm -rf build
	rm -rf bin

format:
	clang-format -i $(addprefix src/,$(shell ls src)) $(addprefix include/,$(shell ls include))

