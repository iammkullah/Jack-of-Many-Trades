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
    public partial class Billing : Form
    {
        public Billing()
        {
            InitializeComponent();
            showDataInLaptopsDataGridView();
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
            laptopListDataGridView.DataSource = dataset.Tables["LaptopTable"];
            sqlConnection.Close();

        }


        int n = 0;
        int DGVTotal = 0;
        int amount = 0;
        private void addToBill_Click(object sender, EventArgs e)
        {
            if (LaptopQuantityTextBox.Text == "" || Convert.ToInt32(LaptopQuantityTextBox.Text) > stock || Convert.ToInt32(LaptopQuantityTextBox.Text) == 0)
            {
                MessageBox.Show("Enter Quantity");
            }
            else
            {
                int total = Convert.ToInt32(LaptopQuantityTextBox.Text) * Convert.ToInt32(LaptopPriceTextBox.Text);

                DataGridViewRow row = new DataGridViewRow();
                row.CreateCells(billDataGridView);
                row.Cells[0].Value = n + 1;
                row.Cells[1].Value = LaptopNameTextBox.Text;
                row.Cells[2].Value = LaptopPriceTextBox.Text;
                row.Cells[3].Value = LaptopQuantityTextBox.Text;
                row.Cells[4].Value = total;
                billDataGridView.Rows.Add(row);
                DGVTotal = DGVTotal + total;
                amount = DGVTotal;
                totalLabel.Text = "Total = " + DGVTotal.ToString() + " $";
                n++;
            }

        }

        int stock = 0;
        private void laptopListDataGridView_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex >= 0)
            {
                DataGridViewRow row = this.laptopListDataGridView.Rows[e.RowIndex];

                LaptopNameTextBox.Text = row.Cells["LaptopName"].Value.ToString();
                LaptopPriceTextBox.Text = row.Cells["LaptopPrice"].Value.ToString();

                if (LaptopNameTextBox.Text == "")
                {
                    stock = 0;
                }
                else
                {
                    stock = Convert.ToInt32(row.Cells["LaptopQuantity"].Value.ToString());

                }

            }
        }
        
        private void buyNow_Click(object sender, EventArgs e)
        {
            if (CustomerNameTextBox.Text == "" || DGVTotal == 0)
            {
                MessageBox.Show("Please enter the customer name and add something to bill");
            }
            else
            {
                String message = CustomerNameTextBox.Text.ToString() + " have purchased an order of total " + DGVTotal + " USD. Thank You For Shopping here";
                MessageBox.Show(message);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            new AdminLogin().Show();
            this.Hide();
        }

        
        

        

        
    }
}
