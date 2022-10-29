using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace LaptopShop
{
    public partial class Laptops : Form
    {
        public Laptops()
        {
            InitializeComponent();
            showDataInLaptopsDataGridView();
        }

        public void clearAllTextBoxes()
        {
            LaptopNameTextBox.Text = "";
            LaptopQuantityTextBox.Text = "";
            LaptopPriceTextBox.Text = "";
            LaptopCompanyTextBox.Text = "";
            Key = 0;
        }

        SqlConnection sqlConnection = new SqlConnection(@"Data Source=(LocalDB)\v11.0;AttachDbFilename=C:\Users\muaaz\Documents\LaptopStoreDatabase.mdf;Integrated Security=True;Connect Timeout=30");

        public void showDataInLaptopsDataGridView()
        {
            sqlConnection.Open();
            string query = "SELECT * from LaptopTable";
            SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(query, sqlConnection);
            SqlCommandBuilder sqlCommandBuilder = new SqlCommandBuilder(sqlDataAdapter);
            var dataset = new DataSet();
            sqlDataAdapter.Fill(dataset, "LaptopTable");
            LaptopsDataGridView.DataSource = dataset.Tables["LaptopTable"];
            sqlConnection.Close();

        }

        private void saveButton_Click(object sender, EventArgs e)
        {
            if (LaptopNameTextBox.Text == "" || LaptopQuantityTextBox.Text == "" || LaptopPriceTextBox.Text == "" || LaptopCompanyTextBox.Text == "")
            {

                MessageBox.Show("Please fill all fields");
            }
            else
            {
                try
                {
                    sqlConnection.Open();

                    string query = "INSERT INTO LaptopTable VALUES('" + LaptopNameTextBox.Text + "', " + LaptopQuantityTextBox.Text + " , " + LaptopPriceTextBox.Text + " , '" + LaptopCompanyTextBox.Text + "');";

                    SqlCommand sqlCommand = new SqlCommand(query, sqlConnection);

                    if (sqlCommand.ExecuteNonQuery() != 0)
                    {
                        MessageBox.Show("Laptop data is saved");
                    }
                    sqlConnection.Close();

                    showDataInLaptopsDataGridView();
                    clearAllTextBoxes();
                }
                catch (Exception execption)
                {
                    MessageBox.Show(execption.Message);
                }
            }
        }
        int Key = 0;
        private void LaptopsDataGridView_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {


            if (e.RowIndex >= 0)
            {
                DataGridViewRow row = this.LaptopsDataGridView.Rows[e.RowIndex];

                LaptopNameTextBox.Text = row.Cells["LaptopName"].Value.ToString();
                LaptopQuantityTextBox.Text = row.Cells["LaptopQuantity"].Value.ToString();
                LaptopPriceTextBox.Text = row.Cells["LaptopPrice"].Value.ToString();
                LaptopCompanyTextBox.Text = row.Cells["LaptopCompany"].Value.ToString();

                if (LaptopNameTextBox.Text == "")
                {
                    Key = 0;
                }
                else
                {
                    Key = Convert.ToInt32(row.Cells["LaptopId"].Value.ToString());

                }
            }
        }

        private void deleteButton_Click(object sender, EventArgs e)
        {
            if (Key == 0)
            {

                MessageBox.Show("Select the laptop to be deleted");
            }
            else
            {
                try
                {
                    sqlConnection.Open();

                    string query = "DELETE FROM LaptopTable where LaptopID=" + Key + ";";

                    SqlCommand sqlCommand = new SqlCommand(query, sqlConnection);

                    if (sqlCommand.ExecuteNonQuery() != 0)
                    {
                        MessageBox.Show("Laptop data is deleted");
                    }
                    sqlConnection.Close();

                    showDataInLaptopsDataGridView();
                    clearAllTextBoxes();
                }
                catch (Exception execption)
                {
                    MessageBox.Show(execption.Message);
                }
            }
        }

        private void editButton_Click(object sender, EventArgs e)
        {
            if (LaptopNameTextBox.Text == "" || LaptopQuantityTextBox.Text == "" || LaptopPriceTextBox.Text == "" || LaptopCompanyTextBox.Text == "")
            {
                MessageBox.Show("Select the laptop to edit");
            }
            else
            {
                try
                {
                    sqlConnection.Open();
                    string query = "UPDATE LaptopTable set LaptopName=" + "'" + LaptopNameTextBox.Text + "'" + ", LaptopQuantity=" + LaptopQuantityTextBox.Text + " , LaptopPrice="  + LaptopPriceTextBox.Text + "  , LaptopCompany='" + LaptopCompanyTextBox.Text + "' WHERE LaptopId=" + Key + ";";

                    SqlCommand sqlCommand = new SqlCommand(query, sqlConnection);

                    if (sqlCommand.ExecuteNonQuery() != 0)
                    {
                        MessageBox.Show("Employee data is edited");
                    }
                    sqlConnection.Close();

                    showDataInLaptopsDataGridView();
                    clearAllTextBoxes();
                }
                catch (Exception execption)
                {
                    MessageBox.Show(execption.Message);
                }
            }
        }

        private void searchButton_Click(object sender, EventArgs e)
        {
            if (LaptopNameTextBox.Text == "")
            {

                MessageBox.Show("Please fill laptop name field");
            }
            else
            {
                try
                {
                    sqlConnection.Open();

                    string query = "SELECT * FROM LaptopTable WHERE LaptopName='" + LaptopNameTextBox.Text + "';";

                    SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(query, sqlConnection);
                    SqlCommandBuilder sqlCommandBuilder = new SqlCommandBuilder(sqlDataAdapter);
                    var dataset = new DataSet();
                    sqlDataAdapter.Fill(dataset, "LaptopTable");
                    LaptopsDataGridView.DataSource = dataset.Tables["LaptopTable"];
                    clearAllTextBoxes();
                }
                catch (Exception execption)
                {
                    MessageBox.Show(execption.Message);
                }
            }
        }

        private void label2_Click(object sender, EventArgs e)
        {
            new Employee().Show();
            this.Hide();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            new Login().Show();
            this.Hide();
        }

       

    }
}

