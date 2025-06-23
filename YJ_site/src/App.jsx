import './App.css'
import { BrowserRouter as Router,
    Routes,
    Route,
    Link 
} from "react-router-dom"
import Header from './Pages/Header/Header'
import MainPage from './Pages/Main/MainPage'

function App() {
  return (
    <>
    <Header />
    <MainPage />
    </>
  )
}

export default App
