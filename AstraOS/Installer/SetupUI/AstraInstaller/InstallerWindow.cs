using System;
using System.Drawing;
using System.Windows.Forms;

namespace AstraInstaller
{
    public class InstallerWindow : Form
    {
        Button btnInstall;
        Button btnExit;
        Label lblTitle;

        public InstallerWindow()
        {
            // Form ayarları
            this.FormBorderStyle = FormBorderStyle.None;
            this.StartPosition = FormStartPosition.CenterScreen;
            this.Width = 600;
            this.Height = 400;
            this.BackColor = Color.FromArgb(0, 90, 180);   // MAVİ ARKAPLAN
            this.DoubleBuffered = true;

            // OVAL PENCERE
            this.Paint += RoundedWindow;

            // Başlık
            lblTitle = new Label();
            lblTitle.Text = "AstraOS Kurulum";
            lblTitle.Font = new Font("Segoe UI", 20, FontStyle.Bold);
            lblTitle.ForeColor = Color.White;
            lblTitle.AutoSize = true;
            lblTitle.Location = new Point(180, 70);
            Controls.Add(lblTitle);

            // Yükle Butonu
            btnInstall = new Button();
            btnInstall.Text = "AstraOS'i Yükle";
            btnInstall.Font = new Font("Segoe UI", 12);
            btnInstall.Size = new Size(200, 45);
            btnInstall.Location = new Point(200, 150);
            btnInstall.Click += InstallOS;
            Controls.Add(btnInstall);

            // Çıkış Butonu
            btnExit = new Button();
            btnExit.Text = "Çıkış";
            btnExit.Font = new Font("Segoe UI", 12);
            btnExit.Size = new Size(200, 45);
            btnExit.Location = new Point(200, 210);
            btnExit.Click += (s, e) => Application.Exit();
            Controls.Add(btnExit);
        }

        // Oval pencere
        private void RoundedWindow(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            g.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.AntiAlias;

            Rectangle box = new Rectangle(100, 50, 400, 300);
            int radius = 40;

            using (Brush b = new SolidBrush(Color.FromArgb(10, 10, 10)))
            {
                using (System.Drawing.Drawing2D.GraphicsPath path = RoundedRect(box, radius))
                {
                    g.FillPath(b, path);
                }
            }
        }

        private System.Drawing.Drawing2D.GraphicsPath RoundedRect(Rectangle bounds, int radius)
        {
            int d = radius * 2;
            var path = new System.Drawing.Drawing2D.GraphicsPath();
            path.AddArc(bounds.X, bounds.Y, d, d, 180, 90);
            path.AddArc(bounds.Right - d, bounds.Y, d, d, 270, 90);
            path.AddArc(bounds.Right - d, bounds.Bottom - d, d, d, 0, 90);
            path.AddArc(bounds.X, bounds.Bottom - d, d, d, 90, 90);
            path.CloseFigure();
            return path;
        }

        private void InstallOS(object sender, EventArgs e)
        {
            MessageBox.Show("AstraOS kurulumu başlatılıyor...\n(Simülasyon)", 
                "Kurulum", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }
    }
}
