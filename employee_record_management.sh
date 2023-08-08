#!/bin/bash

# Write a menu driven program to create Employee record !!

function display_menu() {
    echo ""
    echo "Please select number according to the below listed menu :"
    echo "1. Create Employee Record"
    echo "2. Search Employee Record"
    echo "3. Display Employee Details"
    echo "4. Delete Employee Record"
    echo "5. Sort Records"
    echo "6. List All Records"
    echo "7. Exit"

}

function create_record(){
    read -p "Enter employee name : " name
    read -p "Enter employee number : " emp_number
    read -p "Enter employee Phone number : " ph_number

    if grep -c "^.*:$emp_number:.*$" employee_records.txt
    then 
        echo "Employee Number $emp_number already exists!!"
    else
        echo "$name:$emp_number:$ph_number" >> employee_records.txt
        echo "Employee record created successfully!!"
    fi
}

function search_record(){
    read -p "Enter the Employee number : " emp_number
    if grep -i "^.*:$emp_number:.*$" employee_records.txt
    then 
        :
    else
        echo "No such record exists!!"
    fi
}

function display_employee_details(){
    search_record
}

function delete_record(){
    read -p "Enter the Employee number to be deleted : " emp_num
    if grep -i "^.*:$emp_num:.*$" employee_records.txt > new.txt
    then
        grep -v "^.*:$emp_num:.*$" employee_records.txt > new.txt
        mv new.txt employee_records.txt
        echo "Employee Record deleted successfully!!"
    else
        rm new.txt
        echo "No such record exists!!"
    fi
}

function sort_records(){
    sort -t ':' -k 2n employee_records.txt > temp.txt
    mv temp.txt  employee_records.txt 
    echo "Employee record sorted successfully!!"
}

function list_all_records(){
    while read line
    do 
        echo $line
    done < employee_records.txt
}

while true
do 
    display_menu
    read -p "Enter you choice (1-7) : " choice

    case $choice in 
        1)
            create_record
            ;;
        2)
            search_record
            ;;
        3)
            display_employee_details
            ;;
        4)
            delete_record
            ;;
        5)  
            sort_records
            ;;
        6)
            list_all_records
            ;;
        7)
            echo "LET'S EXIT !!"
            exit 0 
            ;;
        *)
            echo "You have entered a wrong value!! Please select between (1-7)."
            ;;

    esac
done