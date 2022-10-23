function TodoReducer(todoList, action) {
  if (action.type === 'add') {
    return [{
      id: action.id,
      text: action.text,
      isComplete: false
    }, ...todoList];
  } else if (action.type === 'delete') {
    return todoList.filter(todo => todo.id !== action.id);
  } else if (action.type === 'complete') {
    return todoList.map(todo => {
      if (todo.id === action.id) {
        return {
          ...todo,
          isComplete: !todo.isComplete
        };
      }
      return todo;
    });
  } else {
    throw Error('Invalid Action => ' + action.type);
  }
}

export default TodoReducer;