import React, {useState} from "react";
import "./calculator.css"
function Calculator(){
    const [expression,SetExpression] = useState("");
    const handleClick = (value) => {
        SetExpression((prev)=> prev+value);
    };
    const handleClear = () => {
        SetExpression("");
    };
    const handleCalculate = () => {
        try {
            const result = eval(expression);
            SetExpression(result.toString());
        } catch (error){
            SetExpression("Error");
        }
    };

    return(
        <div className="Calculator-main">
            <h1>Calculator</h1>
            <div className="Calculator-input">
                <input type="text" value={expression} readOnly placeholder="Enter expression" />
            </div>
            <div className="Calculator-buttons">
                <button onClick={() => handleClick("1")}>1</button>
                <button onClick={() => handleClick("2")}>2</button>
                <button onClick={() => handleClick("3")}>3</button>
                <button onClick={() => handleClick("+")}>+</button>
                <br />
                <button onClick={() => handleClick("4")}>4</button>
                <button onClick={() => handleClick("5")}>5</button>
                <button onClick={() => handleClick("6")}>6</button>
                <button onClick={() => handleClick("-")}>-</button>
                <br />
                <button onClick={() => handleClick("7")}>7</button>
                <button onClick={() => handleClick("8")}>8</button>
                <button onClick={() => handleClick("9")}>9</button>
                <button onClick={() => handleClick("*")}>*</button>
                <br />
                <button onClick={handleClear}>C</button>
                <button onClick={() => handleClick("0")}>0</button>
                <button onClick={handleCalculate}>=</button>
                <button onClick={() => handleClick("/")}>/</button>
                <br />
            </div>
        </div>
    )
}
export default Calculator;