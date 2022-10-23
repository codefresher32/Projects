import React, { useState, useContext } from 'react';
import { TodoContext } from '../../context/TodoContext';
import { TodoFormInput } from './TodoFormStyle';

function TodoForm() {
  const escKey = 27;
  const enterKey = 13;
  const [input, setInput] = useState('');
  const [isFocused, setIsFocused] = useState(false);
  const { dispatch } = useContext(TodoContext);

  const onFocus = () => setIsFocused(true);
  
  const onBlur = () => setIsFocused(false);

  const handleChange = (event) => {
    setInput(event.target.value);
  };

  const addTodo = () => {
    const newTodo = {
      type: 'add',
      id: Math.floor(Math.random() * 10000),
      text: input,
      isComplete: false
    };
    dispatch(newTodo);
    setInput('');
    setIsFocused(false);
  };

  const onEscKeyPress = () => {
    setInput("");
    setIsFocused(false);
  };

  const handleKeydown = (event) => {
    if(event.keyCode === escKey) {
      onEscKeyPress();
    } else if(event.keyCode === enterKey) {
      addTodo();
    }
  };

  return (
    <>
      { isFocused ? <p>Focused</p> : <></> }
      <TodoFormInput
        placeholder="Add a note"
        type="text"
        autoFocus
        onFocus={onFocus}
        onBlur={onBlur}
        onKeyDown={handleKeydown}
        value={input}
        onChange={handleChange}
      />
    </>
  );
};

export default TodoForm;
