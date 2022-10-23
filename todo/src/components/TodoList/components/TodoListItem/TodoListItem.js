import { useContext } from 'react';
import { TodoContext } from '../../../../context/TodoContext';
import { SingleTodo, Icons, TodoText } from './TodoListItemStyle';

function TodoListItem(props) {
  const { dispatch } = useContext(TodoContext);

  const deleteTodo = () => {
    dispatch({
      type: 'delete',
      id: props.todo.id,
    });
  };

  const finishTodo = () => {
    dispatch({
      type: 'complete',
      id: props.todo.id,
    });
  };

  return (
    <SingleTodo>
      <TodoText isComplete={props.todo.isComplete}>
        {props.todo.text}
      </TodoText>
      <Icons>
        <ion-icon name='checkmark-circle-outline' onClick={finishTodo} />
        <ion-icon name='trash' onClick={deleteTodo} />
      </Icons>
    </SingleTodo>
  )
};

export default TodoListItem;
