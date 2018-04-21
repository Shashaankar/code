#!/bin/python


# Import smtplib for the actual sending function
import smtplib

# Import the email modules we'll need
from email.mime.text import MIMEText

#Globals
sender = ""
receiver = ""
email_file = "email_body.txt"
smtp_server = ""
smtp_port = 25
sender_name = "_name_"

"""
@Brief: Send email with SMTP connection object 
"""
def smtp_send(smtp_host, smtp_port, msg, sender, receiver):
    # Send the message via our own SMTP server.
    s = smtplib.SMTP(smtp_host, smtp_port)

    # Handshake for establishing certificates and key
    s.ehlo()
    s.starttls()
    s.ehlo()
    
    s.login(sender_name, "")

    s.sendmail(sender, receiver, msg)
    #s.send_message(msg)
    s.quit()


"""
@Brief: Wrapper to send Email using SMTP connections
# sender: Senders full qualified Email address
# receiver: reeivers full qualified Email address
# smtp_host: Host address for SMTP server
# smtp_port:  port number for SMTP connection
"""
def send_email(sender, receiver, smtp_host, smtp_port, msg):

    message = """From: """ + sender + """ 
    To: """ + receiver + """
    Subject: Weekly report




    Please find below work report for past two weeks:

    """ + msg + """ 
    """

    print message

    # Wrapper for sending Email with SMTP client connection
    smtp_send(smtp_host, smtp_port, message, sender, receiver)


# Open a plain text file for reading.  For this example, assume that
# the text file contains only ASCII characters.
with open(email_file) as fp:
    week_report = fp.read()
send_email(sender, receiver, smtp_server, smptp_port, week_report)
