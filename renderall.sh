FILES=./scene/*
for f in $FILES
    do
        filename=$(basename "$f")
        filename="${filename%.*}"
        filename=$filename".png"
        bin/runner $f -o scene/$filename
    done
