import React, { createContext, useReducer } from 'react';
import TodoReducer from './TodoReducer';

const TodoContext = createContext();

function TodoContextProvider (props) {
  const [todoList, dispatch] = useReducer(TodoReducer, []);

  return <TodoContext.Provider value={{ todoList, dispatch }}>
    { props.children }
  </TodoContext.Provider>
}

export { TodoContextProvider, TodoContext };