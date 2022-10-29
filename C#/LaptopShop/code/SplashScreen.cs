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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        int startPos = 0;
        private void timer1_Tick(object sender, EventArgs e)
        {
            startPos = startPos + 1;
            progressBar.Value = startPos;
            Loading.Text = "Loading... " + startPos + "%";

            if (progressBar.Value == 100)
            {
                progressBar.Value = 0;
                timer1.Stop();
                Login login = new Login();
                login.Show();
                this.Hide();
            }
        }

        private void Splash_Screen_Load(object sender, EventArgs e)
        {
            timer1.Start();
        }
    }
}
