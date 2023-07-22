from cs50 import get_string

card = get_string("Number: ")
n = len(card)-1

if len(card)==13:
    a=[]
    sum=0
    for i in [11, 9, 7, 5, 3, 1]:
        a.append(int((int(card[i])*2)/10) + ((int(card[i])*2)%10))
    for j in a:
        sum += j
    for k in [12,10,8,6,4,2,0]:
        sum += int(card[k])
    sum = sum % 10
    if(sum == 0):
        if(card[0]=='4'):
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")

elif len(card)==15:
    a=[]
    sum=0
    for i in [13, 11, 9, 7, 5, 3, 1]:
        a.append(int((int(card[i])*2)/10) + ((int(card[i])*2)%10))
    for j in a:
        sum += j
    for k in [14, 12,10,8,6,4,2,0]:
        sum += int(card[k])
    sum = sum % 10
    if(sum == 0):
        if(card[0]=='3' and card[1]=='4'):
            print("AMEX")
        elif(card[0]=='3' and card[1]=='7'):
            print("AMEX")
        else:
            print("INVALID")
    else:
        print("INVALID")

elif len(card)==16:
    a=[]
    sum=0
    for i in [14, 12,10,8,6,4,2,0]:
        a.append(int((int(card[i])*2)/10) + ((int(card[i])*2)%10))
    for j in a:
        sum += j
    for k in [15, 13, 11, 9, 7, 5, 3, 1]:
        sum += int(card[k])
    sum = sum % 10
    if(sum == 0):
        if(card[0]=='5'):
            if(card[1]=='1' or card[1]=='2' or card[1]=='3' or card[1]=='4' or card[1]=='5'):
                print("MASTERCARD")
            else:
                print("INVALID")
        elif(card[0]=='4'):
            print("VISA")

        else:
            print("INVALID")
    else:
        print("INVALID")

else:
    print("INVALID")


