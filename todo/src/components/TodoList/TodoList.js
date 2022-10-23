import TodoListItem from './components/TodoListItem/TodoListItem';
import { useContext } from 'react';
import { TodoContext } from '../../context/TodoContext';
import { TodoListDiv } from './TodoListStyle';

function TodoList() {
  const { todoList } = useContext(TodoContext);

  return (
    <>
      {todoList.map((todo) => (
        <TodoListDiv key={todo.id}>
          <TodoListItem todo={todo} />
        </TodoListDiv>
      ))}
    </>
  );
};

export default TodoList;
