.PHONY: all docs black sphinx isort

sphinx:
	cd docs && sphinx-apidoc -o ./source ../template -f && make html

black:
	black template
	black examples
	blackdoc template
	blackdoc examples

isort:
	isort template
	isort examples
	isort docs

rm-docs:
	rm -rf docs/source/gallery
	rm -rf docs/html
 
docs: black isort sphinx
docs-clean: rm-docs docs