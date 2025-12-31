class Calculator:
    def __init__(self) -> None:
        print("Hello!")

    def add(self, num1: float, num2: float) -> float:
        return num1 + num2
    
    def subtract(self, num1: float, num2: float) -> float:
        return num1 - num2
    
    def multiply(self, num1: float, num2: float) -> float:
        return num1 * num2
    
    def divide(self, num1: float, num2: float) -> float:
        return float(num1 / num2)