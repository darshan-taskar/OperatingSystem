create(){
echo "Enter name of address book"
read ab
res=`ls | grep $ab | wc -w`
if [ $res -gt 0 ];
then
echo "File already exists"
else
touch $ab
echo "Address book created"
fi}
display(){
echo "Enter address book name"
read ab
res=`ls | grep $ab | wc -w`
if [ $res -gt 0 ];
then
cat $ab
else
echo "Address book does not exist"
fi
}
insert(){
echo "Enter the address book name"
read ab
res=`ls | grep $ab | wc -w`
if [ $res -gt 0 ];
then
echo "Enter email"
read email
len=`cat $ab | grep $email | wc -w`
if [ $len -gt 0 ];then echo "Email already exits"
else
echo "Enter firstname,lastname,mobilenumber"
read fname lname mobile
record=`echo $fname $lname $email $mobile`
echo $record>>$ab
echo "Record inserted"
fi
else
echo "Address book does not exist"
fi
}
modify(){
echo "Enter the address book name"
read ab
res=`ls | grep $ab | wc -w`
if [ $res -gt 0 ];
then
echo "Enter email"
read email
len=`cat $ab | grep $email | wc -w`
if [ $len -gt 0 ];
thenecho "Modified lname,fname,mobile_no"
read lname fname mobile
new=`echo $lname $fname $mobile`
old=`cat $ab|grep $email`
echo "Old record:$old"
echo "New record:$new"
#sed-search and edit
#i -inside the file
#s-search
sed -i s/"$old"/"$new"/g $ab
echo "Record modified"
else
echo "Email does not exist"
fi
else
echo "Address book does not exist"
fi
}
delete(){
echo "Enter name of address"
read ab
res=`ls | grep $ab | wc -w`
if [ $res -gt 0 ];then
echo "Enter email"
read email
len=`cat $ab | grep $email | wc -w`
if [ $len -gt 0 ];
then
old=`cat $ab | grep $email`
sed -i s/"$old"//g $ab
#to remove blank online
#^-starting with
#$-for blank line
sed -i /^$/d $ab
echo "Record deleted"
else
echo "Email does not exist"
fi
else
echo "Address book does not exist"
fi
}
while [ true ]
do
echo "******Menu******"
echo "1.create"echo "2.display"
echo "3.insert record"
echo "4.modify"
echo "5.delete"
echo "6.exit"
echo "enter choice:"
read choice
case $choice in
1) create ;;
2) display ;;
3) insert;;
4) modify;;
5) delete ;;
6) exit ;;
*) echo "Wrong choice";;
esac
done