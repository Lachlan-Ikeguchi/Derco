config:
	cd server && make config
	cd client && make config

build: config
	cd server && make build
	cd client && make build

clean:
	cd server && make clean
	cd client && make clean

format:
	cd server && make format
	cd client && make format
