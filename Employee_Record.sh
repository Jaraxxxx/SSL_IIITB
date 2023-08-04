# Problem: Demo on Complex Shell Script
# Write a menu driven program to create Employee Record.
# The Record should contains: Employee Name, Employee Number, and Telephone Number.
# The script should be able to delete a record, search and display a specific employee details, sort the record and list the complete record.

#!usr/bin/bash
declare -A database
echo "Welcome to the Employee Management System"
while true; do
    echo "Menu:
        1. Create Employee Record.
        2. Delete Employee Record.
        3. Search Employee Record.
        4. Display Employee Record.
        5. Sort Employee Records.
        6. List Employee Records.
        7. Exit."
    read optn
    case "$optn" in
        1)
            echo "Enter Employee Record Details : "
            echo "Employee ID : " 
            read id
            echo "Employee name : "
            read name
            database+=([$id]=$name)
            echo "Employee "$id" & "$name" record added successfully"
        ;; 
        2)
            echo "Delete Employee ID : "
            read id
            if [ ${database[$id]+_} ]; 
            then 
                unset database[$id]
                echo "Employee $id removed successfully"; 
            else 
                echo "Not found"; 
            fi
        ;;
        3)
            echo "Search Employee ID : "
            read id
            echo "ID       Name" 
            if [ ${database[$id]+_} ]; 
            then 
                echo "Employee $id exists in the record"; 
            else 
                echo "Not found"; 
            fi
        ;;
        4)
            echo "Employee ID :"
            read id
            echo "ID       Name" 
            if [ ${database[$id]+_} ]; 
            then 
                echo ""$id"        "${database[$id]}""
            else 
                echo "Record not found"; 
            fi
        ;;
        5)
            echo "Sorted Employee Record List : "
            for key in "${!database[@]}"; do
                printf '%s:%s\n' "$key" "${database[$key]}"
            done | sort -t : -k 1n
        ;;
        6)
            echo "List of Employee Record : "
            for key in "${!database[@]}"; do
                echo "$key => ${database[$key]}"; 
            done
        ;;
        7)
            echo "Thank You for using the script"
            exit 1
        ;;
    esac
done
