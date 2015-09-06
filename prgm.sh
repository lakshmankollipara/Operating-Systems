if [ $# -ne 3 ]
then
echo "you have to entered 3 arguments"
exit 3;
else 
if grep "$1" "$2" > "$3"
then
echo pattern found
exit;
else
echo pattern not found
fi
fi

