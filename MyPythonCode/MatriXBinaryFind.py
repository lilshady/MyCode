#coding=utf-8  
#一个矩阵，每行从左到右递增，每列从上到下递增，给定一个
#元素，求其是否在矩阵中。
#Keys：左下角或者右上角元素。

def MatrixBinaryFind(matrix,target):
	row_num = len(matrix)
	col_num = len(matrix[0])
	if row_num == 0 or col_num ==0:
	    print "No!"
	    return False
	elif  matrix[0][col_num-1] == target:
		print "Find"
		return True

	elif matrix[0][col_num-1] > target:
		new_matrix = [row[0:-1] for row in matrix]
		return MatrixBinaryFind(new_matrix,target)

	else:
		return MatrixBinaryFind(matrix[1:],target)


matrix = [[1,2,8,9],[2,4,9,12],[4,7,10,13],[6,8,11,15]]


print MatrixBinaryFind(matrix,5)

