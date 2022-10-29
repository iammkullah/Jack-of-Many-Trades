namespace LaptopShop
{
    partial class Billing
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.billDataGridView = new System.Windows.Forms.DataGridView();
            this.Column1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column2 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column3 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column4 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column5 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.label1 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.addToBill = new System.Windows.Forms.Button();
            this.LaptopQuantityTextBox = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.LaptopPriceTextBox = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.LaptopNameTextBox = new System.Windows.Forms.TextBox();
            this.buyNow = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.panel1 = new System.Windows.Forms.Panel();
            this.label7 = new System.Windows.Forms.Label();
            this.laptopListDataGridView = new System.Windows.Forms.DataGridView();
            this.totalLabel = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.CustomerNameTextBox = new System.Windows.Forms.TextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.billDataGridView)).BeginInit();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.laptopListDataGridView)).BeginInit();
            this.SuspendLayout();
            // 
            // billDataGridView
            // 
            this.billDataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.billDataGridView.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Column1,
            this.Column2,
            this.Column3,
            this.Column4,
            this.Column5});
            this.billDataGridView.Location = new System.Drawing.Point(374, 79);
            this.billDataGridView.Name = "billDataGridView";
            this.billDataGridView.Size = new System.Drawing.Size(517, 219);
            this.billDataGridView.TabIndex = 31;
            // 
            // Column1
            // 
            this.Column1.HeaderText = "ID";
            this.Column1.Name = "Column1";
            // 
            // Column2
            // 
            this.Column2.HeaderText = "Laptop";
            this.Column2.Name = "Column2";
            // 
            // Column3
            // 
            this.Column3.HeaderText = "Price";
            this.Column3.Name = "Column3";
            // 
            // Column4
            // 
            this.Column4.HeaderText = "Quantity";
            this.Column4.Name = "Column4";
            // 
            // Column5
            // 
            this.Column5.HeaderText = "Total";
            this.Column5.Name = "Column5";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 21.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(380, 19);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(180, 33);
            this.label1.TabIndex = 6;
            this.label1.Text = "Laptop Store";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(401, 21);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(70, 25);
            this.label5.TabIndex = 29;
            this.label5.Text = "Billing";
            // 
            // addToBill
            // 
            this.addToBill.Location = new System.Drawing.Point(91, 211);
            this.addToBill.Name = "addToBill";
            this.addToBill.Size = new System.Drawing.Size(134, 23);
            this.addToBill.TabIndex = 26;
            this.addToBill.Text = "Add to Bill";
            this.addToBill.UseVisualStyleBackColor = true;
            this.addToBill.Click += new System.EventHandler(this.addToBill_Click);
            // 
            // LaptopQuantityTextBox
            // 
            this.LaptopQuantityTextBox.Location = new System.Drawing.Point(166, 106);
            this.LaptopQuantityTextBox.Name = "LaptopQuantityTextBox";
            this.LaptopQuantityTextBox.Size = new System.Drawing.Size(134, 20);
            this.LaptopQuantityTextBox.TabIndex = 25;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(166, 139);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(82, 13);
            this.label8.TabIndex = 22;
            this.label8.Text = "Customer Name";
            // 
            // LaptopPriceTextBox
            // 
            this.LaptopPriceTextBox.Enabled = false;
            this.LaptopPriceTextBox.Location = new System.Drawing.Point(15, 166);
            this.LaptopPriceTextBox.Name = "LaptopPriceTextBox";
            this.LaptopPriceTextBox.Size = new System.Drawing.Size(134, 20);
            this.LaptopPriceTextBox.TabIndex = 21;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(15, 139);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(31, 13);
            this.label3.TabIndex = 20;
            this.label3.Text = "Price";
            // 
            // LaptopNameTextBox
            // 
            this.LaptopNameTextBox.Enabled = false;
            this.LaptopNameTextBox.Location = new System.Drawing.Point(15, 106);
            this.LaptopNameTextBox.Name = "LaptopNameTextBox";
            this.LaptopNameTextBox.Size = new System.Drawing.Size(134, 20);
            this.LaptopNameTextBox.TabIndex = 18;
            // 
            // buyNow
            // 
            this.buyNow.Location = new System.Drawing.Point(609, 349);
            this.buyNow.Name = "buyNow";
            this.buyNow.Size = new System.Drawing.Size(75, 23);
            this.buyNow.TabIndex = 13;
            this.buyNow.Text = "Buy Now";
            this.buyNow.UseVisualStyleBackColor = true;
            this.buyNow.Click += new System.EventHandler(this.buyNow_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(15, 79);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(40, 13);
            this.label4.TabIndex = 10;
            this.label4.Text = "Laptop";
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.button1);
            this.panel1.Controls.Add(this.label7);
            this.panel1.Controls.Add(this.laptopListDataGridView);
            this.panel1.Controls.Add(this.totalLabel);
            this.panel1.Controls.Add(this.label2);
            this.panel1.Controls.Add(this.CustomerNameTextBox);
            this.panel1.Controls.Add(this.billDataGridView);
            this.panel1.Controls.Add(this.label5);
            this.panel1.Controls.Add(this.addToBill);
            this.panel1.Controls.Add(this.LaptopQuantityTextBox);
            this.panel1.Controls.Add(this.label9);
            this.panel1.Controls.Add(this.label8);
            this.panel1.Controls.Add(this.LaptopPriceTextBox);
            this.panel1.Controls.Add(this.label3);
            this.panel1.Controls.Add(this.LaptopNameTextBox);
            this.panel1.Controls.Add(this.buyNow);
            this.panel1.Controls.Add(this.label4);
            this.panel1.Location = new System.Drawing.Point(12, 83);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(917, 450);
            this.panel1.TabIndex = 5;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.Location = new System.Drawing.Point(106, 254);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(88, 20);
            this.label7.TabIndex = 36;
            this.label7.Text = "Laptop List";
            // 
            // laptopListDataGridView
            // 
            this.laptopListDataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.laptopListDataGridView.Location = new System.Drawing.Point(15, 277);
            this.laptopListDataGridView.Name = "laptopListDataGridView";
            this.laptopListDataGridView.Size = new System.Drawing.Size(282, 160);
            this.laptopListDataGridView.TabIndex = 35;
            this.laptopListDataGridView.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.laptopListDataGridView_CellContentClick);
            // 
            // totalLabel
            // 
            this.totalLabel.AutoSize = true;
            this.totalLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.totalLabel.Location = new System.Drawing.Point(623, 314);
            this.totalLabel.Name = "totalLabel";
            this.totalLabel.Size = new System.Drawing.Size(44, 20);
            this.totalLabel.TabIndex = 34;
            this.totalLabel.Text = "Total";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(623, 46);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(29, 20);
            this.label2.TabIndex = 33;
            this.label2.Text = "Bill";
            // 
            // CustomerNameTextBox
            // 
            this.CustomerNameTextBox.Location = new System.Drawing.Point(166, 166);
            this.CustomerNameTextBox.Name = "CustomerNameTextBox";
            this.CustomerNameTextBox.Size = new System.Drawing.Size(134, 20);
            this.CustomerNameTextBox.TabIndex = 32;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(166, 79);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(46, 13);
            this.label9.TabIndex = 24;
            this.label9.Text = "Quantity";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(839, 424);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 37;
            this.button1.Text = "Logout";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // Billing
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(941, 552);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.panel1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "Billing";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Billing";
            ((System.ComponentModel.ISupportInitialize)(this.billDataGridView)).EndInit();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.laptopListDataGridView)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView billDataGridView;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Button addToBill;
        private System.Windows.Forms.TextBox LaptopQuantityTextBox;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.TextBox LaptopPriceTextBox;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox LaptopNameTextBox;
        private System.Windows.Forms.Button buyNow;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox CustomerNameTextBox;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column1;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column2;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column3;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column4;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column5;
        private System.Windows.Forms.Label totalLabel;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.DataGridView laptopListDataGridView;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Button button1;
    }
}