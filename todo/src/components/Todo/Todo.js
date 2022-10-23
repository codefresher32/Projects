import TodoForm from '../TodoForm/TodoForm';
import TodoList from '../TodoList/TodoList';
import { TodoDiv } from './TodoStyle';
import { TodoContextProvider } from '../../context/TodoContext';

function Todo() {

  return (
      <TodoDiv>
          <h2>Todo App</h2>
          <TodoContextProvider>
            <TodoForm />
            <TodoList />
          </TodoContextProvider>
      </TodoDiv>
  )
};

export default Todo;
