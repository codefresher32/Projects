import styled from '@emotion/styled/macro';

const Icons = styled.div`
  display: flex;
  row-gap: 15px;
  display: none;
`;
const SingleTodo = styled.div`
  width: 100%;
  height: auto;
  padding: 10;
  margin: 5;
  white-space: nowrap; 
  text-overflow: ellipsis;
  overflow: hidden;
  :hover ${Icons} {
    display: flex;
    flex-direction: row;
    align-items: center;
    font-size: 25px;
    cursor: pointer;
    position: absolute;
    top: 15px;
    right: 10px;
    z-index: 2;
  }
`;
const TodoText = styled.p`
  text-decoration: none;
  color: green;
  ${({ isComplete }) => isComplete &&
    `text-decoration: line-through;
     color: rgb(17, 9, 9);`
  }
`;

export { SingleTodo, Icons, TodoText };
