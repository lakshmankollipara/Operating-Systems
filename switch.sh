echo "menu
1)list of files
2)date
3)cal
4)quit"
echo "enter your option:\c"
read choice
echo
case "$choice" in
1) ls -l;;
2) date;;
3) cal;;
4) exit;;
esac
