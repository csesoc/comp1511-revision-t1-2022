for d in */tests; do
	cd $d
	pwd
	zip tests.zip * -r
	cd ../..
done
