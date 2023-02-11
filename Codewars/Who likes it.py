def likes(names):
    text = ''
    if names:
        text += names[0]
        if len(names) == 2:
            text += ' and ' + names[1] + ' like this'
        elif len(names) == 3:    
            text += ', ' + names[1]
            text += ' and ' + names[2] + ' like this'
        elif len(names) > 3:
            text += ', ' + names[1] + ' and '
            text += str(len(names)-2) + ' others like this'   
        else:
            text += ' likes this'
    else:
        text += 'no one likes this'
    return text

print(likes([]))
print(likes(['Peter']))
print(likes(['Jacob', 'Alex']))
print(likes(['Max', 'John', 'Mark']))
print(likes(['Alex', 'Jacob', 'Mark', 'Max']))