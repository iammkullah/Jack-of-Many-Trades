package com.company;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Customer extends Shop {

    String customerName;
    String customerGender;
    int customerAvailableBalance;

    static ArrayList<Customer> customers = new ArrayList<Customer>() ;

    // ---------------------- searchCustomers() ----------------------- //

    static int searchCustomers( String name){

        boolean found = false ;
        int index = -1;

        for (int i = 0 ; i < customers.size() ; i++){

            Customer customer = (Customer)customers.get(i);

            if (name.equals(customer.customerName)){
                found = true ;
                index = i;

            }

        }

        return index ;

    }

    // ---------------------- editCustomers() ----------------------- //

    static void editCustomers(int indexNumber , String customerName , String customerGender , int customerAvailableBalance){


        Customer customer = new Customer(customerName , customerGender , customerAvailableBalance) ;
        customers.set(indexNumber , customer ) ;


    }

    // ---------------------- deleteCustomers() ----------------------- //

    static void deleteCustomers(int indexNumber){

        customers.remove(indexNumber);

    }

    // ---------------------- addCustomers() ----------------------- //

    static void addCustomers(Customer customer){

        customers.add(customer) ;

//        saveCustomerData(customers);
    }

    // ---------------------- saveCustomerData() ----------------------- //

    public static void saveCustomerData(List<Customer> customers){

        FileWriter fileWriter = null; // FileWriter: Node Stream for writing
        PrintWriter printWriter = null; // PrintWriter: Filter Stream for writing
        try {

            // if file does not exist, it automatically create for you

            String string = "" ;

//            fileWriter = new FileWriter("CustomerData.txt") ;
            fileWriter = new FileWriter("customers.txt") ;

            printWriter = new PrintWriter(fileWriter) ;

            for (int i = 0 ; i < customers.size() ; i++){

                string = "Customer" + i +" : " +  "," + customers.get(i).customerName + "," + customers.get(i).customerGender + "," + customers.get(i).customerAvailableBalance + "," ;

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

    // ---------------------- loadCustomerData() ----------------------- //

    public static void loadCustomerData(){



        FileReader fileReader = null; // FileReader: Node Stream for reading
        BufferedReader bufferedReader = null; // BufferedReader: Filter Stream for reading
        try {
//            fileReader = new FileReader("CustomerData.txt");
            fileReader = new FileReader("customers.txt");

            bufferedReader = new BufferedReader(fileReader);
            String str = bufferedReader.readLine();
            while (str != null) {

                String[] tokens = str.split(",");

                Customer customer = new Customer(tokens[1] , tokens[2] , Integer.parseInt(tokens[3]) ) ;

                customers.add(customer) ;

//                System.out.println(str);

                str = bufferedReader.readLine();


            }
            bufferedReader.close();
            fileReader.close();
        } catch (Exception e) {

            Customer muaaz = new Customer("Muaaz Shoaib" ,"Male" , 2000);
            Customer haider = new Customer("Haider Ali" ,"Male", 3000);
            Customer zohaib = new Customer("Zohaib Ahmer" , "Male" , 4000);

            Customer.addCustomers(muaaz);
            Customer.addCustomers(haider);
            Customer.addCustomers(zohaib);

            Customer.saveCustomerData(Customer.customers);
//            Customer.loadCustomerData();

            System.out.println(e);


        }

    }

    // ---------------------- Constructors ----------------------- //

    public Customer(int i) {

        Scanner input = new Scanner(System.in);

        System.out.println("Enter customerName " + i );

        this.customerName = input.nextLine() ;

        System.out.println("Enter customerGender " + i );

        this.customerGender = input.nextLine() ;

        System.out.println("Enter customerAvailableBalance " + i );

        this.customerAvailableBalance = input.nextInt() ;

    }


    public Customer(String customerName, String customerGender, int customerAvailableBalance) {
        this.customerName = customerName;
        this.customerGender = customerGender;
        this.customerAvailableBalance = customerAvailableBalance;
    }


}

