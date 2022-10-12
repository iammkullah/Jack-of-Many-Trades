#rotate the image
def rotateImage(a):
    n = len(a)
    for i in range(n//2):
        for j in range(i, n-i-1):
            temp = a[i][j]
            a[i][j] = a[n-1-j][i]
            a[n-1-j][i] = a[n-1-i][n-1-j]
            a[n-1-i][n-1-j] = a[j][n-1-i]
            a[j][n-1-i] = temp
    return a