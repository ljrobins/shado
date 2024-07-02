.PHONY: all docs black sphinx isort bump

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

bump:
	bump2version patch --allow-dirty

 
docs: black isort sphinx
docs-clean: rm-docs docs