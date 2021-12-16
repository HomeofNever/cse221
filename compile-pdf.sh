# bash
for var in "$@"
do
    FILE_PATH=$(readlink -f $var)
    NEW_PATH=${FILE_PATH%.md}.pdf
    pandoc header-includes.yaml $FILE_PATH -o $NEW_PATH --pdf-engine=lualatex
done