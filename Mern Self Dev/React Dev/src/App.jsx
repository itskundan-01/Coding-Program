import "./App.css"
import { Routes, Route, useNavigate } from "react-router-dom";
import Calculator from "./calculator.jsx"

function App(){
  const navigate = useNavigate();
  const handleOpenCalculator = () => {
    navigate("/calculator");
  }

  return (
    <div className="App">
    <Routes>
      <Route
        path="/"
        element={
          <div>
            <h1>Hello World, I am Kundan Kumar</h1>
            <div>
              <h2>Click on the below button to open Calculator</h2>
              <button onClick={handleOpenCalculator}>Open Calculator</button>
            </div>
          </div>
        }
      />
      <Route path="/calculator" element={<Calculator />} />
    </Routes>
    </div>
  )
}

export default App;