import smtplib

def sendAlert (curr_user):

    #email properties
    sent_from = "153berkeley@gmail.com"
    to = 'tramphuonglam@gmail.com'
    subject = "testing from code"
    email_text = "hello from uwuplants!"

    #email send request
    try:
        server = smtplib.SMTP_SSL('smtp.gmail.com', 465)
        server.ehlo()

        #login to sender acc
        server.login("153berkeley@gmail.com", "A406Roomies")

        #send email
        server.sendmail(sent_from, to, email_text)
        server.close()

        print ('Email sent!')
    except Exception as e:
        print(e)
        print ('Something went wrong...')