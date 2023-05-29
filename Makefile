PACKAGE_NAME = matvec
VERSION = 1.0.0

.PHONY: all clean test

all:
	pip uninstall ${PACKAGE_NAME} -y
	pip install --upgrade pip build
	python3 -m build
	pip install ./dist/${PACKAGE_NAME}-${VERSION}.tar.gz

test:
	python3 -m unittest discover -s .srcs/tests/

clean:
	rm -rf ./dist
	rm -rf ./build
	rm -rf ./*.egg-info

fclean: clean
	pip uninstall ${PACKAGE_NAME} -y