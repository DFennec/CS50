import qrcode
img = qrcode.QRCode(
    version=1,
    error_correction=qrcode.constants.ERROR_CORRECT_L,
    box_size=10,
    border=4,
)
img.add_data('https://www.youtube.com')
img.make(fit=True)
img = img.make_image(fill_color=(100,0,255), back_color="black")
type(img)
img.save("generatedQR.png")
