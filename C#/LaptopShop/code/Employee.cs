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
    public partial class Employee : Form
    {
        public Employee()
        {
            InitializeComponent();
            showDataInEmployeeDataGridView();
        }

        public void clearAllTextBoxes()
        {
            EmployeeNameTextBox.Text = "";
            EmployeePhoneTextBox.Text = "";
            EmployeeAddressTextBox.Text = "";
            EmployeePasswordTextBox.Text = "";
            Key = 0;
        }

        SqlConnection sqlConnection = new SqlConnection(@"Data Source=(LocalDB)\v11.0;AttachDbFilename=C:\Users\muaaz\Documents\LaptopStoreDatabase.mdf;Integrated Security=True;Connect Timeout=30");

        public void showDataInEmployeeDataGridView()
        {
            sqlConnection.Open();
            string query = "SELECT * from EmployeeTable";
            SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(query, sqlConnection);
            SqlCommandBuilder sqlCommandBuilder = new SqlCommandBuilder(sqlDataAdapter);
            var dataset = new DataSet();
            sqlDataAdapter.Fill(dataset, "EmployeeTable");
            EmployeesDataGridView.DataSource = dataset.Tables["EmployeeTable"];
            sqlConnection.Close();

        }
        private void saveButton_Click(object sender, EventArgs e)
        {
            if (EmployeeNameTextBox.Text == "" || EmployeePhoneTextBox.Text == "" || EmployeeAddressTextBox.Text == "" || EmployeePasswordTextBox.Text == "")
            {

                MessageBox.Show("Please fill all fields");
            }
            else
            {
                try
                {
                    sqlConnection.Open();

                    string query = "INSERT INTO EmployeeTable VALUES('" + EmployeeNameTextBox.Text + "', " + EmployeePhoneTextBox.Text + " , '" + EmployeeAddressTextBox.Text + "' , " + EmployeePasswordTextBox.Text + ")";

                    SqlCommand sqlCommand = new SqlCommand(query, sqlConnection);

                    if (sqlCommand.ExecuteNonQuery() != 0)
                    {
                        MessageBox.Show("Employee data is saved");
                    }
                    sqlConnection.Close();

                    showDataInEmployeeDataGridView();
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
            if (EmployeeNameTextBox.Text == "" || EmployeePhoneTextBox.Text == "" || EmployeeAddressTextBox.Text == "" || EmployeePasswordTextBox.Text == "")
            {
                MessageBox.Show("Select the employee to edit");
            }
            else
            {
                try
                {
                    sqlConnection.Open();
                    string query = "UPDATE EmployeeTable set EmployeeName=" + "'" + EmployeeNameTextBox.Text + "'" + ", EmployeePhone=" + EmployeePhoneTextBox.Text + " , EmployeeAddress=" + "'" + EmployeeAddressTextBox.Text + "'" + "  , EmpPassword=" + EmployeePasswordTextBox.Text + "WHERE EmployeeId=" + Key + ";";

                    SqlCommand sqlCommand = new SqlCommand(query, sqlConnection);

                    if (sqlCommand.ExecuteNonQuery() != 0)
                    {
                        MessageBox.Show("Employee data is edited");
                    }
                    sqlConnection.Close();

                    showDataInEmployeeDataGridView();
                    clearAllTextBoxes();
                }
                catch (Exception execption)
                {
                    MessageBox.Show(execption.Message);
                }
            }

        }

        int Key = 0;
        private void EmployeesDataGridView_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex >= 0)
            {
                DataGridViewRow row = this.EmployeesDataGridView.Rows[e.RowIndex];

                EmployeeNameTextBox.Text = row.Cells["EmployeeName"].Value.ToString();
                EmployeePhoneTextBox.Text = row.Cells["EmployeePhone"].Value.ToString();
                EmployeeAddressTextBox.Text = row.Cells["EmployeeAddress"].Value.ToString();
                EmployeePasswordTextBox.Text = row.Cells["EmpPassword"].Value.ToString();

                //EmployeeNameTextBox.Text = EmployeesDataGridView.SelectedRows[0].Cells[1].Value.ToString();
                //EmployeePhoneTextBox.Text = EmployeesDataGridView.SelectedRows[0].Cells[2].Value.ToString();
                //EmployeeAddressTextBox.Text = EmployeesDataGridView.SelectedRows[0].Cells[3].Value.ToString();
                //EmployeePasswordTextBox.Text = EmployeesDataGridView.SelectedRows[0].Cells[4].Value.ToString();

                if (EmployeeNameTextBox.Text == "")
                {
                    Key = 0;
                }
                else
                {
                    Key = Convert.ToInt32(row.Cells["EmployeeId"].Value.ToString());

                }
            }
        }

        private void deleteButton_Click(object sender, EventArgs e)
        {
            if (Key == 0)
            {

                MessageBox.Show("Select the employee to be deleted");
            }
            else
            {
                try
                {
                    sqlConnection.Open();

                    string query = "DELETE FROM EmployeeTable where EmployeeID=" + Key + ";";

                    SqlCommand sqlCommand = new SqlCommand(query, sqlConnection);

                    if (sqlCommand.ExecuteNonQuery() != 0)
                    {
                        MessageBox.Show("Employee data is deleted");
                    }
                    sqlConnection.Close();

                    showDataInEmployeeDataGridView();
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
            if (EmployeeNameTextBox.Text == "")
            {

                MessageBox.Show("Please fill employee name field");
            }
            else
            {
                try
                {
                    sqlConnection.Open();

                    string query = "SELECT * FROM EmployeeTable WHERE EmployeeName='" + EmployeeNameTextBox.Text + "';";

                    SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(query, sqlConnection);
                    SqlCommandBuilder sqlCommandBuilder = new SqlCommandBuilder(sqlDataAdapter);
                    var dataset = new DataSet();
                    sqlDataAdapter.Fill(dataset, "EmployeeTable");
                    EmployeesDataGridView.DataSource = dataset.Tables["EmployeeTable"];
                    clearAllTextBoxes();
                }
                catch (Exception execption)
                {
                    MessageBox.Show(execption.Message);
                }
            }
        }

        private void label5_Click(object sender, EventArgs e)
        {
            new Laptops().Show();
            this.Hide();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            new Login().Show();
            this.Hide();
        }
    }
}




