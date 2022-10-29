using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LaptopShop
{
    public partial class AdminLogin : Form
    {
        public AdminLogin()
        {
            InitializeComponent();
        }

        String adminPassword = "admin";

        private void admin_Login_Click(object sender, EventArgs e)
        {
            if (passwordTextBox.Text == "")
            {
                MessageBox.Show("Please fill all fields");
            }
            else
            {
                if (passwordTextBox.Text == adminPassword)
                {
                    Employee employee = new Employee();
                    employee.Show();
                    this.Hide();
                }
                else
                {
                    MessageBox.Show("Admin password is incorrect");
                }
            }
        }

        private void label1_Click(object sender, EventArgs e)
        {
            new Login().Show();
            this.Hide();
        }
    }
}
