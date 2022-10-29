package com.company;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class SignUp_GUI {

    public SignUp_GUI() {
        SignUp.loadSignUpData();
        initGUI();
    }

    public void initGUI() {


        if (SignUp.signUps.get(0).userName == " " || SignUp.signUps.get(0).email == " " || SignUp.signUps.get(0).password == " ") {
            logIn();
            signUp();

        } else {
            logIn();
        }


    }

    public void signUp() {

//         Step 2 : Setup the top level container
        JFrame signUp = new JFrame();

// Step 3 : Get the component Aera of the top level Container
        Container container = signUp.getContentPane();

// Step 4 : Apply layout to that Aera
        container.setLayout(new GridLayout(5, 1));
        container = signUp.getContentPane();

// Step 5 : Create and add components

        JLabel jLabel = new JLabel("Sign Up Page");

        Container container1 = new Container();

        container1.add(new JLabel("Enter User Name :"));
        JTextField userName = new JTextField(10);
        container1.add(userName);

        container1.setLayout(new FlowLayout());

        Container container2 = new Container();

        container2.add(new JLabel("Enter Email :"));
        JTextField email = new JTextField(10);
        container2.add(email);

        container2.setLayout(new FlowLayout());

        Container container3 = new Container();

        container3.add(new JLabel("Set password :"));
        JTextField password = new JTextField(10);
        container3.add(password);

        container3.setLayout(new FlowLayout());

        JButton signUpButton = new JButton("Sign Up!");

        signUpButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {


                if (e.getActionCommand().equals("Sign Up!")) {
                    System.out.println("Sign Up! --> Button Pressed !");

                    System.out.println("Username = " + SignUp.signUps.get(0).userName);
                    System.out.println("email = " + SignUp.signUps.get(0).email);
                    System.out.println("password = " + SignUp.signUps.get(0).password);


                    SignUp signUp1 = new SignUp(userName.getText(), email.getText(), password.getText());

                    userName.setText(null);
                    email.setText(null);
                    password.setText(null);

                    SignUp.replaceSignUps(signUp1);

                    SignUp.saveSignUpData(SignUp.signUps);

                    signUp.setVisible(false);


                }

            }
        });

        container.add(jLabel);
        container.add(container1);
        container.add(container2);
        container.add(container3);
        container.add(signUpButton);


// Step 6 : Set size of Frame and make it Visible
        signUp.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        signUp.setSize(300, 500);
        signUp.setVisible(true);

        signUp.addWindowListener(new WindowAdapter() {

            @Override
            public void windowClosing(WindowEvent e) {
                super.windowClosing(e);


                SignUp.saveSignUpData(SignUp.signUps);


                JOptionPane.showMessageDialog(null, "Good Bye / Thanks You");

                System.exit(0);
            }

        });


    }

    public void logIn() {

//         Step 2 : Setup the top level container
        JFrame logIn = new JFrame();

// Step 3 : Get the component Aera of the top level Container
        Container container = logIn.getContentPane();

// Step 4 : Apply layout to that Aera
        container.setLayout(new GridLayout(5, 1));
        container = logIn.getContentPane();

// Step 5 : Create and add components

        JLabel jLabel = new JLabel("Login Page");

        Container container1 = new Container();

        container1.add(new JLabel("Enter User Name :"));
        JTextField userName = new JTextField(10);
        container1.add(userName);

        container1.setLayout(new FlowLayout());

        Container container2 = new Container();

        container2.add(new JLabel("Enter password :"));
        JTextField password = new JTextField(10);
        container2.add(password);

        container2.setLayout(new FlowLayout());


        JButton logInButton = new JButton("Log In!");

        logInButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                if (e.getActionCommand().equals("Log In!")) {

                    System.out.println("Log In! --> Button Pressed !");

                    System.out.println("Username = " + SignUp.signUps.get(0).userName);
                    System.out.println("email = " + SignUp.signUps.get(0).email);
                    System.out.println("password = " + SignUp.signUps.get(0).password);

                    String USERNAME, PASSWORD;

                    USERNAME = userName.getText();
                    PASSWORD = password.getText();

                    if (USERNAME.equals(SignUp.signUps.get(0).userName) && PASSWORD.equals(SignUp.signUps.get(0).password)) {

                        JOptionPane.showMessageDialog(null, "Successfully Login");

//                        JOptionPane.showMessageDialog(null, "User name is : " + SignUp.signUps.get(0).userName + " \n " +
//                                "Email is : " + SignUp.signUps.get(0).email + "\n" +
//                                "Password is : " + SignUp.signUps.get(0).password + "\n");

                        System.out.println("Successfully Login");

                        logIn.setVisible(false);

                        GUI gui = new GUI();


                    }


                }

            }
        });

        container.add(jLabel);
        container.add(container1);
        container.add(container2);
        container.add(logInButton);


// Step 6 : Set size of Frame and make it Visible
        logIn.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        logIn.setSize(300, 500);
        logIn.setVisible(true);

        logIn.addWindowListener(new WindowAdapter() {

            @Override
            public void windowClosing(WindowEvent e) {
                super.windowClosing(e);

                SignUp.saveSignUpData(SignUp.signUps);

                JOptionPane.showMessageDialog(null, "Good Bye / Thanks You");

                System.exit(0);
            }

        });


    }

}

class SignUp {

    static ArrayList<SignUp> signUps = new ArrayList<SignUp>();
    String userName;
    String email;
    String password;


    public SignUp(String userName, String email, String password) {
        this.userName = userName;
        this.email = email;
        this.password = password;
    }

    static void addSignUps(SignUp signUp) {

        signUps.add(signUp);

    }

    static void replaceSignUps(SignUp signUp) {

        signUps.set(0, signUp);

    }

    public static void saveSignUpData(List<SignUp> signUps) {

        FileWriter fileWriter = null;
        PrintWriter printWriter = null;
        try {


            String string = "";

//            fileWriter = new FileWriter("SignUpData.txt") ;
            fileWriter = new FileWriter("signUps.txt");

            printWriter = new PrintWriter(fileWriter);

            for (int i = 0; i < signUps.size(); i++) {

                string = "SignUp" + i + " : " + "," + signUps.get(i).userName + "," + signUps.get(i).email + "," + signUps.get(i).password + ",";

                printWriter.println(string);

            }

            printWriter.flush(); // flush() --> to flush/clear the stream

            printWriter.close();
            fileWriter.close();

        } catch (Exception exception) {

            System.out.println(exception);

        }

    }

    public static void loadSignUpData() {


        FileReader fileReader = null;
        BufferedReader bufferedReader = null;
        try {
//            fileReader = new FileReader("SignUpData.txt");
            fileReader = new FileReader("signUps.txt");

            bufferedReader = new BufferedReader(fileReader);
            String str = bufferedReader.readLine();
            while (str != null) {

                String[] tokens = str.split(",");

                SignUp signUp = new SignUp(tokens[1], tokens[2], tokens[3]);

                signUps.add(signUp);

//                System.out.println(str);

                str = bufferedReader.readLine();


            }
            bufferedReader.close();
            fileReader.close();
        } catch (Exception e) {

//            (String userName, String email, String password)

            SignUp admin = new SignUp(" ", " ", " ");


            SignUp.addSignUps(admin);


            SignUp.saveSignUpData(SignUp.signUps);


            System.out.println(e);


        }

    }

}
