def determinant(D):
    ans=1
    for i in range(len(D)):
        if(D[i][i]==0):
            for j in range(i+1,len(D)):
                if(D[j][i]!=0):
                    (D[i],D[j])=(D[j],D[i])
                    break
        if(D[i][i]<0):
            for j in range(i,len(D)):
                D[i][j]*=-1
        ans*=D[i][i]
        if(ans==0):
            return(0)
        for j in range(i+1,len(D)):
            q=D[j][i]/D[i][i]
            if(q==0):
                continue
            for k in range(i,len(D)):
                D[j][k]-=D[i][k]*q
        print(D)
    return(int(round(ans)))
