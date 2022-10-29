package com.company;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Product extends Shop {

    String productName;
    String productType;
    int productPrice;

    static ArrayList<Product> products = new ArrayList<Product>() ;

    // ---------------------- searchProducts() ----------------------- //

    static int searchProducts( String name){

        boolean found = false ;
        int index = -1;

        for (int i = 0 ; i < products.size() ; i++){

            Product product = (Product)products.get(i);

            if (name.equals(product.productName)){
                found = true ;
                index = i;

            }

        }

        return index ;

    }

    // ---------------------- editProduct() ----------------------- //

    static void editProduct(int indexNumber , String productName , int productPrice){


        Product product = new Product(productName  , productPrice) ;
        products.set(indexNumber , product ) ;


    }

    // ---------------------- deleteProduct() ----------------------- //

    static void deleteProduct(int indexNumber){

        products.remove(indexNumber);

    }

    // ---------------------- addProducts() ----------------------- //

    static void addProducts(Product product){

        products.add(product) ;

//        saveProductData(products);
    }

    // ---------------------- saveProductData() ----------------------- //

    public static void saveProductData(List<Product> products){

        FileWriter fileWriter = null; // FileWriter: Node Stream for writing
        PrintWriter printWriter = null; // PrintWriter: Filter Stream for writing
        try {

            // if file does not exist, it automatically create for you

            String string = "" ;

//            fileWriter = new FileWriter("ProductData.txt") ;
            fileWriter = new FileWriter("products.txt") ;

            printWriter = new PrintWriter(fileWriter) ;

            for (int i = 0 ; i < products.size() ; i++){

                string = "Product" + i +" : " +  "," + products.get(i).productName + "," + products.get(i).productType + "," + products.get(i).productPrice + "," ;

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

    // ---------------------- loadProductData() ----------------------- //

    public static void loadProductData(){


        FileReader fileReader = null; // FileReader: Node Stream for reading
        BufferedReader bufferedReader = null; // BufferedReader: Filter Stream for reading
        try {
//            fileReader = new FileReader("ProductData.txt");
            fileReader = new FileReader("products.txt");

            bufferedReader = new BufferedReader(fileReader);
            String str = bufferedReader.readLine();
            while (str != null) {

                    String[] tokens = str.split(",");

                    Product product = new Product(tokens[1] , tokens[2] , Integer.parseInt(tokens[3]) ) ;

                    products.add(product) ;

                    str = bufferedReader.readLine();

            }
            bufferedReader.close();
            fileReader.close();
        } catch (Exception e) {

            Product macBookAir = new Product("MacBook Air" , 999);
            Product hpSpecter = new Product("HP Specter" , 1200);
            Product dellXPS13 = new Product("Dell XPS 13" , 1250);

            Product.addProducts(macBookAir);
            Product.addProducts(hpSpecter);
            Product.addProducts(dellXPS13);

            Product.saveProductData(Product.products);

//            Product.loadProductData();

            System.out.println(e);
        }

    }

    // ---------------------- Constructors() ----------------------- //

    public Product(String productName, String productType, int productPrice) {
        this.productName = productName;
        this.productType = productType;
        this.productPrice = productPrice;
    }

    public Product(String productName, int productPrice) {
        this.productName = productName;
        this.productType = "Laptop" ;
        this.productPrice = productPrice;
    }

    public Product(int i) {

        Scanner input = new Scanner(System.in);

        System.out.println("Enter productName " + i );

        this.productName = input.nextLine() ;

        this.productType = "Laptops" ;

        System.out.println("Enter productPrice " + i );

        this.productPrice = input.nextInt() ;

    }

}
