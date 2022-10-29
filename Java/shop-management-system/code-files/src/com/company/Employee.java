package com.company;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Employee extends Shop {

    String employeeName;
    String employeeGender;
    int employeeSalary;

    static ArrayList<Employee> employees = new ArrayList<Employee>() ;

    // ---------------------- searchEmployees() ----------------------- //

    static int searchEmployees( String name){

        boolean found = false ;
        int index = -1;

        for (int i = 0 ; i < employees.size() ; i++){

            Employee employee = (Employee)employees.get(i);

            if (name.equals(employee.employeeName)){
                found = true ;
                index = i;

            }

        }

        return index ;

    }

    // ---------------------- editEmployees() ----------------------- //

    static void editEmployees(int indexNumber , String employeeName , String employeeGender , int employeeSalary){


        Employee employee = new Employee(employeeName , employeeGender , employeeSalary) ;
        employees.set(indexNumber , employee ) ;


    }

    // ---------------------- deleteEmployees() ----------------------- //

    static void deleteEmployees(int indexNumber){

        employees.remove(indexNumber);

    }

    // ---------------------- addEmployees() ----------------------- //

    static void addEmployees(Employee employee){

        employees.add(employee) ;

//        saveEmployeeData(employees);
    }

    // ---------------------- saveEmployeeData() ----------------------- //

    public static void saveEmployeeData(List<Employee> employees){

        FileWriter fileWriter = null; // FileWriter: Node Stream for writing
        PrintWriter printWriter = null; // PrintWriter: Filter Stream for writing
        try {

            // if file does not exist, it automatically create for you

            String string = "" ;

//            fileWriter = new FileWriter("EmployeeData.txt") ;
            fileWriter = new FileWriter("employees.txt") ;

            printWriter = new PrintWriter(fileWriter) ;

            for (int i = 0 ; i < Employee.employees.size() ; i++){

                string = "Employee" + i +" : " +  "," + employees.get(i).employeeName + "," + employees.get(i).employeeGender + "," + employees.get(i).employeeSalary + "," ;

                printWriter.println(string);

            }

            printWriter.flush(); // flush() --> to flush/clear the stream

            printWriter.close();
            fileWriter.close();

        }
        catch (Exception exception) {

            System.out.println(exception);

        }

    }

    // ---------------------- loadEmployeeData() ----------------------- //

    public static void loadEmployeeData(){



        FileReader fileReader = null; // FileReader: Node Stream for reading
        BufferedReader bufferedReader = null; // BufferedReader: Filter Stream for reading
        try {
//            fileReader = new FileReader("EmployeeData.txt");
            fileReader = new FileReader("employees.txt");

            bufferedReader = new BufferedReader(fileReader);
            String str = bufferedReader.readLine();
            while (str != null) {

                String[] tokens = str.split(",");

                Employee employee = new Employee(tokens[1] , tokens[2] , Integer.parseInt(tokens[3]) ) ;

                employees.add(employee) ;

//                System.out.println(str);

                str = bufferedReader.readLine();


            }
            bufferedReader.close();
            fileReader.close();
        } catch (Exception e) {

            Employee muaaz = new Employee("Muaaz Shoaib" ,"Male" , 2000);
            Employee haider = new Employee("Haider Ali" ,"Male", 3000);
            Employee zohaib = new Employee("Zohaib Ahmer" , "Male" , 4000);

            Employee.addEmployees(muaaz);
            Employee.addEmployees(haider);
            Employee.addEmployees(zohaib);

            Employee.saveEmployeeData(Employee.employees);
//            Employee.loadEmployeeData();

            System.out.println(e);


        }

    }

    // ---------------------- Constructors ----------------------- //

    public Employee(int i) {

        Scanner input = new Scanner(System.in);

        System.out.println("Enter EmployeeName " + i );

        this.employeeName = input.nextLine() ;

        System.out.println("Enter employeeGender " + i );

        this.employeeGender = input.nextLine() ;

        System.out.println("Enter employeeSalary " + i );

        this.employeeSalary = input.nextInt() ;

    }


    public Employee(String employeeName, String employeeGender, int employeeSalary) {
        this.employeeName = employeeName;
        this.employeeGender = employeeGender;
        this.employeeSalary = employeeSalary;
    }


}

