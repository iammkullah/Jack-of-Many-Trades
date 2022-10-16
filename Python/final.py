#Creat a final heap matrix
def heap_matrix(matrix):
    heap_matrix = []
    for i in range(len(matrix)):
        heap_matrix.append([])
        for j in range(len(matrix[i])):
            heap_matrix[i].append(matrix[i][j])
    return heap_matrix