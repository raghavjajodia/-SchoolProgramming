def evaluate_poly(poly,x):
    summ=0
    for i in range(len(poly)):
        summ=summ+poly[i]*(x**i)
    return summ

def compute_deri(poly):
    newpoly=()
    for i in range(1,len(poly)):
        newpoly=newpoly+(poly[i]*i,)
    return newpoly

##poly = (-13.39, 0.0, 17.5, 3.0, 1.0)
##
##print compute_deri(poly)

def compute_root(poly, x_0, epsilon,count):
    if abs(evaluate_poly(poly,x_0))<epsilon:
        return (x_0,count)
    else:
        x_n=x_0-evaluate_poly(poly,x_0)/evaluate_poly(compute_deri(poly),x_0)
        count=count+1
        return compute_root(poly,x_n,epsilon,count)

poly=(-13.39, 0.0, 17.5, 3.0, 1.0)

x_0 = 0.1
epsilon = .0001

print compute_root(poly, x_0, epsilon,1)



                   


