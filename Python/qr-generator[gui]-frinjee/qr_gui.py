import tkinter as ttk
from tkinter import Button, Canvas, Label
from tkinter import StringVar, Entry
from PIL import Image, ImageTk
import os, qrcode

global qr_displbl 
global qr_disp_img 

root = ttk.Tk()
root.title('QR Generator')
root.geometry('')
root.configure(background='#4a4d4f')

qr_prvw = ttk.Frame(root)
qr_prvw.grid(row=0, column=0, padx=2, pady=2)

cvs = ttk.Canvas(qr_prvw, bg='#fff', width=250, height=100)
cvs.grid(row=0, column=0, rowspan=3, padx=1, pady=1)

label_frame = ttk.Frame(root)
label_frame.grid(row=2, column=0, sticky='w', padx=2, pady=2)

content = ttk.Label(label_frame, text='Enter content to store: ', width=20)
content.grid(row=3, column=0)
file_saved = ttk.Label(label_frame, text='Enter file name: ', width=16)
file_saved.grid(row=4, column=0)

content = StringVar()
content_entry = ttk.Entry(label_frame, textvariable=content)
content_entry.grid(row=3, column=1)

file_saved = StringVar()
file_entry = ttk.Entry(label_frame, textvariable=file_saved)
file_entry.grid(row=4, column=1)

qr = qrcode.QRCode(version = 2, box_size = 6, border = 5)

def gen_QR():

	if len(content.get()) !=0:
		qr.add_data(content.get())
		qr.make(fit=True)
		qr_img = qr.make_image(fill_color='blue', back_color='white')
		file_name_png = file_saved.get() + '.png'
		qr_img.save(file_name_png)

		_ = Image.open(file_name_png)
		qr_disp_img = ImageTk.PhotoImage(_)

		qr_displbl = ttk.Label(qr_prvw, image=qr_disp_img)
		qr_displbl.grid(row=0, column=0)

		cvs.create_image(10, 10, anchor=NW, image=qr_disp_img)


	else:
		print('no')


gen_btn = ttk.Button(root, text='Generate & Save', width=15, relief='groove', padx=2, pady=2, command=gen_QR)
gen_btn.grid(row=4, column=0, rowspan=2, columnspan=2)



root.mainloop()


