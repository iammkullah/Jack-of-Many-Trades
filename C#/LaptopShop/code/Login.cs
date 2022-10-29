using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LaptopShop
{
    public partial class Login : Form
    {
        public Login()
        {
            InitializeComponent();
        }

        private void label4_Click(object sender, EventArgs e)
        {
            new AdminLogin().Show();
            this.Hide();
        }
        SqlConnection sqlConnection = new SqlConnection(@"Data Source=(LocalDB)\v11.0;AttachDbFilename=C:\Users\muaaz\Documents\LaptopStoreDatabase.mdf;Integrated Security=True;Connect Timeout=30");

        private void employeeLogin_Click(object sender, EventArgs e)
        {
            if (employeeIDTextBox.Text == "" || passwordTextBox.Text == "")
            {
                MessageBox.Show("Please fill all fields");
            }
            else
            {
                try
                {
                    sqlConnection.Open();

                    string query = "SELECT COUNT(*) FROM EmployeeTable WHERE EmployeeId='" + employeeIDTextBox.Text + "' AND EmpPassword='" + passwordTextBox.Text + "'";

                    SqlDataAdapter sda = new SqlDataAdapter(query, sqlConnection);
                    /* in above line the program is selecting the whole data from table and the matching it with the user name and password provided by user. */
                    DataTable dt = new DataTable(); //this is creating a virtual table  
                    sda.Fill(dt);
                    Console.WriteLine(dt.Rows[0][0].ToString());
                    if (dt.Rows[0][0].ToString() == "1")
                    {
                        /* I have made a new page called home page. If the user is successfully authenticated then the form will be moved to the next form */
                        this.Hide();
                        new Billing().Show();
                    }
                    else
                        MessageBox.Show("Invalid username or password");
                }
                catch (Exception execption)
                {
                    MessageBox.Show(execption.Message);
                }
            }
        }
    }
}
