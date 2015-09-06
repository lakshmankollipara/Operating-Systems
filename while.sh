while true
do
echo "enter a file name"
read fname
cc $fname
case "$?" in
0) echo "compilation successful"
echo "executing c program"
./a.out;
exit;;
*) echo "compilation failed"
echo "press enter to edit"
read pause
vi $fname
esac
done
