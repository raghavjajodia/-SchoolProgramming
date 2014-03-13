#Problem Set 1A
#Name: Niki Castle
#Collaborators: none
#Time Spent: ~1hr

#Get values for original balance, interest rate, and minimum monthly payment.

balance = float(raw_input('Enter the outstanding balance on your credit card: '))
amountPaid = 0
interest = float(raw_input('Enter the annual credit card interest rate as a decimal: '))
minPay = float(raw_input('Enter the minimum monthly payment rate as a decimal: '))

#Calculate payment, principal paid, and interest for each of 12 months.

for month in range(1,13):
    print 'Month: ' + str(month)
    print 'Minimum monthly payment: ' + str(round(minPay*balance,2))
    amountPaid = float(amountPaid+minPay*balance)
    principal = float(balance*(minPay-interest/12))
    print 'Principal paid: ' + str(round(principal,2))
    balance = float(balance-principal)
    print 'Remaining balance: ' + str(round(balance,2))

#Print totals after 12 months.

print 'RESULT'
print 'Total amount paid: ' + str(round(amountPaid,2))
print 'Remaining balance: ' + str(round(balance,2))
