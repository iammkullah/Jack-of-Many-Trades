package com.company;


import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.ArrayList;

public class GUI {

    JList jList = new JList();

    // ---------------------- employeeListUpdate() ----------------------- //

    public JList employeeListUpdate(){

        ArrayList<String> employee = new ArrayList<String>();


        for (int i = 0 ; i < Employee.employees.size() ; i++){

            employee.add(i + " -  Name : " + " , " + Employee.employees.get(i).employeeName +  " Gender :  , " + Employee.employees.get(i).employeeGender + " Salary :  , " + Employee.employees.get(i).employeeSalary  +" USD ");

        }

        JList jList = new JList( employee.toArray());

        JScrollPane scrollPane = new JScrollPane();
        scrollPane.setViewportView(jList);
        jList.setLayoutOrientation(JList.VERTICAL);

        return jList;

    }


    // ---------------------- customerListUpdate() ----------------------- //

    public JList customerListUpdate(){

        ArrayList<String> customer = new ArrayList<String>();


        for (int i = 0 ; i < Customer.customers.size() ; i++){

            customer.add(i + " -  Name : " + " , " + Customer.customers.get(i).customerName +  " Gender :  , " + Customer.customers.get(i).customerGender + " Available Balance :  , " + Customer.customers.get(i).customerAvailableBalance  +" USD ");

        }

        JList jList = new JList( customer.toArray());

        JScrollPane scrollPane = new JScrollPane();
        scrollPane.setViewportView(jList);
        jList.setLayoutOrientation(JList.VERTICAL);

        return jList;

    }

    // ---------------------- productListUpdate() ----------------------- //



    public JList productListUpdate(){

        ArrayList<String> product = new ArrayList<String>();


        for (int i = 0 ; i < Product.products.size() ; i++){

            product.add(i + " -  Name : " + " , " + Product.products.get(i).productName +  " Category :  , " + Product.products.get(i).productType + " Price :  , " + Product.products.get(i).productPrice  +" USD ");

        }

        JList jList = new JList( product.toArray());

        JScrollPane scrollPane = new JScrollPane();
        scrollPane.setViewportView(jList);
        jList.setLayoutOrientation(JList.VERTICAL);

        return jList;

    }





    // ---------------------- welcomePanel() ----------------------- //

    public JPanel welcomePanel(){

        JPanel welcomePanel = new JPanel(new GridLayout(20 , 1 ));

        welcomePanel.add(new JLabel("Welcome to my project !"));
        welcomePanel.add(new JLabel(" "));
        welcomePanel.add(new JLabel( "Project : Shop Management System"  ));
        welcomePanel.add(new JLabel(" "));

        welcomePanel.add(new JLabel("Shop Name : " + Shop.shopName));
        welcomePanel.add(new JLabel("Shop Type : " + Shop.shopType));

        welcomePanel.add(new JLabel(" "));
        welcomePanel.add(new JLabel(" "));
        welcomePanel.add(new JLabel(" "));

        welcomePanel.add(new JLabel("OOP Assignment 3 & 4"));
        welcomePanel.add(new JLabel("Muhammad Muaaz Shoaib"));
        welcomePanel.add(new JLabel("FA20 - BCS - 074"));
        welcomePanel.add(new JLabel(" "));

        return welcomePanel;

    }

    // ---------------------- productPanel() ----------------------- //

    public JPanel productPanel(){


// -------------------------- 1 - productPanel ----------------------- //

        JPanel productPanel = new JPanel(new GridLayout(5 , 1) );

        // --------------------------------------- 1 - 1 manageProductJLabel ----------------------- //

        JLabel manageProductJLabel = new JLabel(" Manage Products ") ;

        // --------------------------------------- 1 - 2 inputProductPanel ----------------------- //

        JPanel inputProductPanel = new JPanel(new GridLayout(3 , 1));

        // --------------------------------------------------------------- 1 - 2 - 1 name ----------------------- //

        JPanel name = new JPanel(new FlowLayout());

        name.add(new JLabel("Name")) ;
        JTextField nameProductTextField = new JTextField(10) ;

        name.add(nameProductTextField) ;

        // --------------------------------------------------------------- 1 - 2 - 2 category ----------------------- //

         JPanel category = new JPanel(new FlowLayout());

        category.add(new JLabel("Category :")) ;
        category.add(new JLabel()) ;
        category.add(new JLabel("Laptop")) ;



        // --------------------------------------------------------------- 1 - 2 - 3 price ----------------------- //

        JPanel price = new JPanel(new FlowLayout());

        price.add(new JLabel("Price")) ;
        JTextField priceProductTextField = new JTextField(10) ;

        price.add(priceProductTextField) ;

        inputProductPanel.add(name);
        inputProductPanel.add(category);
        inputProductPanel.add(price);

        // --------------------------------------- 1 - 4 productDataShowpanel ----------------------- //

        JPanel productDataShowpanel = new JPanel();

        ArrayList<String> product = new ArrayList<String>();


        for (int i = 0 ; i < Product.products.size() ; i++){

            product.add(i + " -  Name : " + Product.products.get(i).productName +  " Category : " + Product.products.get(i).productType + " Price : " + Product.products.get(i).productPrice  +" USD ");

        }

        final JList[] jList = {new JList(product.toArray())};
        JScrollPane scrollPane = new JScrollPane();


        // --------------------------------------- 1 - 2 inputProductPanel ----------------------- //



        // --------------------------------------- 1 - 3 buttonProductPanel ----------------------- //



        JPanel buttonProductPanel = new JPanel(new FlowLayout());

        // --------------------------------------- 1 - 3 - 1 addProduct ----------------------- //

        JButton addProduct = new JButton("Add") ;



        addProduct.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("Add Product --> Button Pressed !");

                boolean addPress = true ;


                for (int i = 0 ; addPress ; i++){

                    Product product = new Product( nameProductTextField.getText()  , Integer.parseInt(priceProductTextField.getText())) ;
                    Product.addProducts(product);
                    addPress = false ;
                }

                JOptionPane.showMessageDialog(null , "Product " + nameProductTextField.getText() +" is added"); ;



                nameProductTextField.setText(null);
                priceProductTextField.setText(null);

                jList[0] = productListUpdate() ;
                scrollPane.setViewportView(jList[0]);
                jList[0].setLayoutOrientation(JList.VERTICAL);


            }
        });

        // --------------------------------------- 1 - 3 - 2 deleteProduct ----------------------- //

        JButton deleteProduct = new JButton("Delete") ;

        deleteProduct.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("Delete Product --> Button Pressed !");

                if (e.getActionCommand().equals("Delete"))
                {
                    int index = jList[0].getSelectedIndex();
                    System.out.println("Index Selected: " + index);
                    String s = (String) jList[0].getSelectedValue();
                    System.out.println("Value Selected: " + s);



                    JOptionPane.showMessageDialog(null , "Product " + Product.products.get(index).productName +" is deleted");
                    Product.deleteProduct(index);

                    nameProductTextField.setText(null);
                    priceProductTextField.setText(null);

                    jList[0] = productListUpdate() ;
                    scrollPane.setViewportView(jList[0]);
                    jList[0].setLayoutOrientation(JList.VERTICAL);
                }

            }
        });

        // --------------------------------------- 1 - 3 - 3 editProduct ----------------------- //

        JButton editProduct = new JButton("Edit") ;

        editProduct.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("Edit Product --> Button Pressed !");

                if (e.getActionCommand().equals("Edit"))
                {
                    int index = jList[0].getSelectedIndex();
                    System.out.println("Index Selected: " + index);
                    String s = (String) jList[0].getSelectedValue();
                    System.out.println("Value Selected: " + s);



                    JOptionPane.showMessageDialog(null , "Product  " + Product.products.get(index).productName +" is edited");

                    JOptionPane.showMessageDialog(null , "New Product name is : " + nameProductTextField.getText() +" \n " +
                            "New Product category is : " + Product.products.get(index).productType + "\n" +
                            "New Product price is : " +  Integer.parseInt(priceProductTextField.getText()) + "\n");

                    Product.editProduct(index , nameProductTextField.getText() , Integer.parseInt(priceProductTextField.getText()) );

                    nameProductTextField.setText(null);
                    priceProductTextField.setText(null);

                    jList[0] = productListUpdate() ;
                    scrollPane.setViewportView(jList[0]);
                    jList[0].setLayoutOrientation(JList.VERTICAL);


                }

            }
        });

        // --------------------------------------- 1 - 3 - 4 searchProduct ----------------------- //

        JButton searchProduct = new JButton("Search") ;

        searchProduct.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("Search Product --> Button Pressed !");

                boolean found = false ;
                int index = -1;

                if (e.getActionCommand().equals("Search"))
                {

                    index = Product.searchProducts(nameProductTextField.getText()) ;

                    if (index == -1){
                        JOptionPane.showMessageDialog(null , nameProductTextField.getText() + " is not found ");

                    }
                    else {

                        JOptionPane.showMessageDialog(null , nameProductTextField.getText() + " is  found ");

                        JOptionPane.showMessageDialog(null , "Product name is : " + Product.products.get(index).productName +" \n " +
                                "Product category is : " + Product.products.get(index).productType  + "\n" +
                                "Product price is : " +  Product.products.get(index).productPrice  + "\n");


                    }

                    nameProductTextField.setText(null);
                    priceProductTextField.setText(null);

                    jList[0] = productListUpdate() ;
                    scrollPane.setViewportView(jList[0]);
                    jList[0].setLayoutOrientation(JList.VERTICAL);

                }

            }
        });

        buttonProductPanel.add(addProduct);
        buttonProductPanel.add(deleteProduct);
        buttonProductPanel.add(editProduct);
        buttonProductPanel.add(searchProduct);




        scrollPane.setViewportView(jList[0]);
        jList[0].setLayoutOrientation(JList.VERTICAL);

        productDataShowpanel.add(scrollPane) ;


// -------------------------- 1 - productPanel ----------------------- //

        productPanel.add(manageProductJLabel);
        productPanel.add(inputProductPanel);
        productPanel.add(buttonProductPanel);
        productPanel.add(productDataShowpanel);
        productPanel.add(new JLabel());

        return productPanel;

    }

    // ---------------------- customerPanel() ----------------------- //

    public JPanel customerPanel(){

        // -------------------------- 1 - customerPanel ----------------------- //

        JPanel customerPanel = new JPanel(new GridLayout(5 , 1) );

        // --------------------------------------- 1 - 1 manageCustomerJLabel ----------------------- //

        JLabel manageCustomerJLabel = new JLabel(" Manage Customers ") ;

        // --------------------------------------- 1 - 4 customerDataShowPanel ----------------------- //

        JPanel customerDataShowPanel = new JPanel();

        ArrayList<String> customer = new ArrayList<String>();


        for (int i = 0 ; i < Customer.customers.size() ; i++){

            customer.add(i + " -  Name : " + Customer.customers.get(i).customerName +  " Gender : " + Customer.customers.get(i).customerGender + " Available Balannce : " + Customer.customers.get(i).customerAvailableBalance  + " USD ");

        }



        final JList[] jList = {new JList(customer.toArray())};
        JScrollPane scrollPane = new JScrollPane();




        // --------------------------------------- 1 - 2 inputCustomerPanel ----------------------- //

        JPanel inputCustomerPanel = new JPanel(new GridLayout(3 , 1));

        // --------------------------------------------------------------- 1 - 2 - 1 name ----------------------- //

        JPanel name = new JPanel(new FlowLayout());

        name.add(new JLabel("Name")) ;

        JTextField nameCustomerTextField = new JTextField(10) ;

        name.add(nameCustomerTextField) ;

        // --------------------------------------------------------------- 1 - 2 - 2 gender ----------------------- //

        JPanel gender = new JPanel(new FlowLayout());

        gender.add(new JLabel("Gender")) ;

        JTextField genderCustomerTextField = new JTextField(10) ;

        gender.add(genderCustomerTextField) ;

        // --------------------------------------------------------------- 1 - 2 - 3 availableBalance ----------------------- //

        JPanel availableBalance = new JPanel(new FlowLayout());

        availableBalance.add(new JLabel("Available Balance")) ;

        JTextField availableBalanceCustomerTextField = new JTextField(10) ;

        availableBalance.add(availableBalanceCustomerTextField) ;

        inputCustomerPanel.add(name);
        inputCustomerPanel.add(gender);
        inputCustomerPanel.add(availableBalance);

        // --------------------------------------- 1 - 2 inputCustomerPanel ----------------------- //



        // --------------------------------------- 1 - 3 buttonProductPanel ----------------------- //

        JPanel buttonProductPanel = new JPanel(new FlowLayout());

        // --------------------------------------- 1 - 3 - 1 addCustomer ----------------------- //

        JButton addCustomer = new JButton("Add") ;

        addCustomer.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("Add Customer --> Button Pressed !");

                boolean addPress = true ;


                for (int i = 0 ; addPress ; i++){

                    Customer customer = new Customer(nameCustomerTextField.getText() , genderCustomerTextField.getText() , Integer.parseInt(availableBalanceCustomerTextField.getText()) );
                    Customer.addCustomers(customer);
                    addPress = false ;

                }

                JOptionPane.showMessageDialog(null , "Customer " + nameCustomerTextField.getText() +" is added"); ;

                nameCustomerTextField.setText(null);
                genderCustomerTextField.setText(null);
                availableBalanceCustomerTextField.setText(null);

                jList[0] = customerListUpdate() ;
                scrollPane.setViewportView(jList[0]);
                jList[0].setLayoutOrientation(JList.VERTICAL);

            }
        });

        // --------------------------------------- 1 - 3 - 2 deleteCustomer ----------------------- //

        JButton deleteCustomer = new JButton("Delete") ;

        deleteCustomer.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                System.out.println("Delete Customer --> Button Pressed !");

                if (e.getActionCommand().equals("Delete"))
                {
                    int index = jList[0].getSelectedIndex();
                    System.out.println("Index Selected: " + index);
                    String s = (String) jList[0].getSelectedValue();
                    System.out.println("Value Selected: " + s);



                    JOptionPane.showMessageDialog(null , "Customer " + Customer.customers.get(index).customerName +" is deleted");
                    Customer.deleteCustomers(index);

                    nameCustomerTextField.setText(null);
                    genderCustomerTextField.setText(null);
                    availableBalanceCustomerTextField.setText(null);

                    jList[0] = customerListUpdate() ;
                    scrollPane.setViewportView(jList[0]);
                    jList[0].setLayoutOrientation(JList.VERTICAL);


                }

            }
        });

        // --------------------------------------- 1 - 3 - 3 editCustomer ----------------------- //

        JButton editCustomer = new JButton("Edit") ;

        editCustomer.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("Edit Customer --> Button Pressed !");

                if (e.getActionCommand().equals("Edit"))
                {
                    int index = jList[0].getSelectedIndex();
                    System.out.println("Index Selected: " + index);
                    String s = (String) jList[0].getSelectedValue();
                    System.out.println("Value Selected: " + s);



                    JOptionPane.showMessageDialog(null , "Customer " + Customer.customers.get(index).customerName +" is edited");

                    JOptionPane.showMessageDialog(null , "New Customer name is : " + nameCustomerTextField.getText() +" \n " +
                            "New Customer gender is : " + genderCustomerTextField.getText() + "\n" +
                            "New Customer available balance is : " +  Integer.parseInt(availableBalanceCustomerTextField.getText()) + "\n");

                    Customer.editCustomers(index , nameCustomerTextField.getText() , genderCustomerTextField.getText() , Integer.parseInt(availableBalanceCustomerTextField.getText()) );

                    nameCustomerTextField.setText(null);
                    genderCustomerTextField.setText(null);
                    availableBalanceCustomerTextField.setText(null);

                    jList[0] = customerListUpdate() ;
                    scrollPane.setViewportView(jList[0]);
                    jList[0].setLayoutOrientation(JList.VERTICAL);


                }

            }
        });

        // --------------------------------------- 1 - 3 - 4 searchCustomer ----------------------- //

        JButton searchCustomer = new JButton("Search") ;

        searchCustomer.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("Search Customer --> Button Pressed !");

                boolean found = false ;
                int index = -1;

                if (e.getActionCommand().equals("Search"))
                {

                    index = Customer.searchCustomers(nameCustomerTextField.getText()) ;

                    if (index == -1){
                        JOptionPane.showMessageDialog(null , nameCustomerTextField.getText() + " is not found ");

                    }
                     else {

                        JOptionPane.showMessageDialog(null , nameCustomerTextField.getText() + " is  found ");

                        JOptionPane.showMessageDialog(null , "Customer name is : " + Customer.customers.get(index).customerName +" \n " +
                                "Customer gender is : " + Customer.customers.get(index).customerGender  + "\n" +
                                "Customer available balance is : " +  Customer.customers.get(index).customerAvailableBalance  + "\n");



                          }

                    nameCustomerTextField.setText(null);
                    genderCustomerTextField.setText(null);
                    availableBalanceCustomerTextField.setText(null);

                    jList[0] = customerListUpdate() ;
                    scrollPane.setViewportView(jList[0]);
                    jList[0].setLayoutOrientation(JList.VERTICAL);

                }

            }
        });

        buttonProductPanel.add(addCustomer);
        buttonProductPanel.add(deleteCustomer);
        buttonProductPanel.add(editCustomer);
        buttonProductPanel.add(searchCustomer);


        scrollPane.setViewportView(jList[0]);
        jList[0].setLayoutOrientation(JList.VERTICAL);

        customerDataShowPanel.add(scrollPane) ;


// -------------------------- 1 - customerPanel ----------------------- //

        customerPanel.add(manageCustomerJLabel);

        customerPanel.add(inputCustomerPanel);
        customerPanel.add(buttonProductPanel);
        customerPanel.add(customerDataShowPanel);
        customerPanel.add(new JLabel());

        return customerPanel;

    }

    // ---------------------- employeePanel() ----------------------- //

    public JPanel employeePanel(){

        // -------------------------- 1 - employeePanel ----------------------- //

        JPanel employeePanel = new JPanel(new GridLayout(5 , 1) );

        // --------------------------------------- 1 - 1 manageEmployeeJLabel ----------------------- //

        JLabel manageEmployeeJLabel = new JLabel(" Manage Employees ") ;

        // --------------------------------------- 1 - 4 employeeDataShowPanel ----------------------- //

        JPanel employeeDataShowPanel = new JPanel();

        ArrayList<String> employee = new ArrayList<String>();


        for (int i = 0 ; i < Employee.employees.size() ; i++){

            employee.add(i + " -  Name : " + Employee.employees.get(i).employeeName +  " Gender : " + Employee.employees.get(i).employeeGender + " Salary : " + Employee.employees.get(i).employeeSalary  + " USD ");

        }



        final JList[] jList = {new JList(employee.toArray())};
        JScrollPane scrollPane = new JScrollPane();




        // --------------------------------------- 1 - 2 inputEmployeePanel ----------------------- //

        JPanel inputEmployeePanel = new JPanel(new GridLayout(3 , 1));

        // --------------------------------------------------------------- 1 - 2 - 1 name ----------------------- //

        JPanel name = new JPanel(new FlowLayout());

        name.add(new JLabel("Name")) ;

        JTextField nameEmployeeTextField = new JTextField(10) ;

        name.add(nameEmployeeTextField) ;

        // --------------------------------------------------------------- 1 - 2 - 2 gender ----------------------- //

        JPanel gender = new JPanel(new FlowLayout());

        gender.add(new JLabel("Gender")) ;

        JTextField genderEmployeeTextField = new JTextField(10) ;

        gender.add(genderEmployeeTextField) ;

        // --------------------------------------------------------------- 1 - 2 - 3 availableBalance ----------------------- //

        JPanel availableBalance = new JPanel(new FlowLayout());

        availableBalance.add(new JLabel("Available Balance")) ;

        JTextField availableBalanceEmployeeTextField = new JTextField(10) ;

        availableBalance.add(availableBalanceEmployeeTextField) ;

        inputEmployeePanel.add(name);
        inputEmployeePanel.add(gender);
        inputEmployeePanel.add(availableBalance);

        // --------------------------------------- 1 - 2 inputEmployeePanel ----------------------- //



        // --------------------------------------- 1 - 3 buttonEmployeePanel ----------------------- //

        JPanel buttonEmployeePanel = new JPanel(new FlowLayout());

        // --------------------------------------- 1 - 3 - 1 addEmployee ----------------------- //

        JButton addEmployee = new JButton("Add") ;

        addEmployee.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("Add Employee --> Button Pressed !");

                boolean addPress = true ;


                for (int i = 0 ; addPress ; i++){

                    Employee employee = new Employee(nameEmployeeTextField.getText() , genderEmployeeTextField.getText() , Integer.parseInt(availableBalanceEmployeeTextField.getText()) );
                    Employee.addEmployees(employee);
                    addPress = false ;

                }

                JOptionPane.showMessageDialog(null , "Employee " + nameEmployeeTextField.getText() +" is added"); ;

                nameEmployeeTextField.setText(null);
                genderEmployeeTextField.setText(null);
                availableBalanceEmployeeTextField.setText(null);

                jList[0] = employeeListUpdate() ;
                scrollPane.setViewportView(jList[0]);
                jList[0].setLayoutOrientation(JList.VERTICAL);

            }
        });

        // --------------------------------------- 1 - 3 - 2 deleteEmployee ----------------------- //

        JButton deleteEmployee = new JButton("Delete") ;

        deleteEmployee.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                System.out.println("Delete Employee --> Button Pressed !");

                if (e.getActionCommand().equals("Delete"))
                {
                    int index = jList[0].getSelectedIndex();
                    System.out.println("Index Selected: " + index);
                    String s = (String) jList[0].getSelectedValue();
                    System.out.println("Value Selected: " + s);



                    JOptionPane.showMessageDialog(null , "Employee " + Employee.employees.get(index).employeeName +" is deleted");
                    Employee.deleteEmployees(index);

                    nameEmployeeTextField.setText(null);
                    genderEmployeeTextField.setText(null);
                    availableBalanceEmployeeTextField.setText(null);

                    jList[0] = employeeListUpdate() ;
                    scrollPane.setViewportView(jList[0]);
                    jList[0].setLayoutOrientation(JList.VERTICAL);


                }

            }
        });

        // --------------------------------------- 1 - 3 - 3 editEmployee ----------------------- //

        JButton editEmployee = new JButton("Edit") ;

        editEmployee.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("Edit Employee --> Button Pressed !");

                if (e.getActionCommand().equals("Edit"))
                {
                    int index = jList[0].getSelectedIndex();
                    System.out.println("Index Selected: " + index);
                    String s = (String) jList[0].getSelectedValue();
                    System.out.println("Value Selected: " + s);



                    JOptionPane.showMessageDialog(null , "Employee " + Employee.employees.get(index).employeeName +" is edited");

                    JOptionPane.showMessageDialog(null , "New Employee name is : " + nameEmployeeTextField.getText() +" \n " +
                            "New Employee gender is : " + genderEmployeeTextField.getText() + "\n" +
                            "New Employee salary is : " +  Integer.parseInt(availableBalanceEmployeeTextField.getText()) + "\n");

                    Employee.editEmployees(index , nameEmployeeTextField.getText() , genderEmployeeTextField.getText() , Integer.parseInt(availableBalanceEmployeeTextField.getText()) );

                    nameEmployeeTextField.setText(null);
                    genderEmployeeTextField.setText(null);
                    availableBalanceEmployeeTextField.setText(null);

                    jList[0] = employeeListUpdate() ;
                    scrollPane.setViewportView(jList[0]);
                    jList[0].setLayoutOrientation(JList.VERTICAL);


                }

            }
        });

        // --------------------------------------- 1 - 3 - 4 searchEmployee ----------------------- //

        JButton searchEmployee = new JButton("Search") ;

        searchEmployee.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("Search Employee --> Button Pressed !");

                boolean found = false ;
                int index = -1;

                if (e.getActionCommand().equals("Search"))
                {

                    index = Employee.searchEmployees(nameEmployeeTextField.getText()) ;

                    if (index == -1){
                        JOptionPane.showMessageDialog(null , nameEmployeeTextField.getText() + " is not found ");

                    }
                    else {

                        JOptionPane.showMessageDialog(null , nameEmployeeTextField.getText() + " is  found ");

                        JOptionPane.showMessageDialog(null , "Employee name is : " + Employee.employees.get(index).employeeName +" \n " +
                                "Employee gender is : " + Employee.employees.get(index).employeeGender  + "\n" +
                                "Employee salary is : " +  Employee.employees.get(index).employeeSalary  + "\n");



                    }

                    nameEmployeeTextField.setText(null);
                    genderEmployeeTextField.setText(null);
                    availableBalanceEmployeeTextField.setText(null);

                    jList[0] = employeeListUpdate() ;
                    scrollPane.setViewportView(jList[0]);
                    jList[0].setLayoutOrientation(JList.VERTICAL);

                }

            }
        });

        buttonEmployeePanel.add(addEmployee);
        buttonEmployeePanel.add(deleteEmployee);
        buttonEmployeePanel.add(editEmployee);
        buttonEmployeePanel.add(searchEmployee);


        scrollPane.setViewportView(jList[0]);
        jList[0].setLayoutOrientation(JList.VERTICAL);

        employeeDataShowPanel.add(scrollPane) ;


// -------------------------- 1 - employeePanel ----------------------- //

        employeePanel.add(manageEmployeeJLabel);

        employeePanel.add(inputEmployeePanel);
        employeePanel.add(buttonEmployeePanel);
        employeePanel.add(employeeDataShowPanel);
        employeePanel.add(new JLabel());

        return employeePanel;

    }

    // ---------------------- initGUI() ----------------------- //

    public void initGUI(){

        JFrame jFrame = new JFrame("Shop Management System");
        jFrame.setLayout(null);

        jFrame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                super.windowClosing(e);

                Product.saveProductData(Product.products);
                Customer.saveCustomerData(Customer.customers);
                Employee.saveEmployeeData(Employee.employees);

                JOptionPane.showMessageDialog( null , "Good Bye / Thanks You");



                System.exit(0);
            }
        });


        JTabbedPane tabs = new JTabbedPane();
        tabs.setBounds(5 , 5 , 475 ,550);
        
        tabs.add( "Welcome" , welcomePanel());
        tabs.add( "Products" , productPanel());
        tabs.add( "Customers" , customerPanel());
        tabs.add( "Employees" , employeePanel());

        jFrame.add(tabs);

        jFrame.setSize(500 , 600);
        jFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        jFrame.setVisible(true);

    }

    // ---------------------- Constructors ----------------------- //


    public GUI() {

        Product.loadProductData();
        Customer.loadCustomerData();
        Employee.loadEmployeeData();

        initGUI();

    }
}
