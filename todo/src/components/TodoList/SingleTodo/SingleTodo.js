import style from './SingleTodo.module.css';

function SingleTodo(props) {

  const handleDelete = () => {
    props.deleteTodo(props.id);
  }

  const handleFinish = () => {
    props.finishTodo(props.id, props.todo);
  }

  return (
    <div className={style['single-todo']}>
      <p className={props.todo.isComplete ? style['checked'] : style['unchecked']} key={props.todo.id}>
        {props.todo.text}
      </p>
      <div className={style['icon-group']}>
        <ion-icon name='checkmark-circle-outline' onClick={handleFinish} />
        <ion-icon name='trash' onClick={handleDelete} />
      </div>
    </div>
  )
}

export default SingleTodo;