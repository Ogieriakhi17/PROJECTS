using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Collections.Generic;
using System.Text.RegularExpressions;
using Avalonia.Controls;

namespace SpreadsheetEngine;

public class Spreadsheet
{

    private class Cell : AbstractCell
    {
        public Cell(int rowIndex, int colIndex) : base(rowIndex, colIndex)
        {
        }

        public override string Value
        {

            get => valuue;
            protected internal set => this.SetField(ref valuue, value);
        }

    }

    private readonly Cell[,] cells;

    // public event PropertyChangedEventHandler? CellPropertyChanged;

    public event PropertyChangedEventHandler? SpreadsheetPropertyChanged;

    public event PropertyChangedEventHandler? BaseCellPropertyChanged;

    // Dictionary<string, List<AbstractCell>> dependencyMap = new Dictionary<string, List<AbstractCell>>();

    /*
     protected virtual void OnPropertyChanged([CallerMemberName] string? propertyName = null)
     {
         this.CellPropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
     }
     */

    /* protected virtual void SpreadPropertyChanged([CallerMemberName] string? propertyName = null)
     {
         this.CellPropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
     }
 */

    public int ColumnCount { get; }

    public int RowCount { get; }

    /*NAME: SPREADSHEET
     *DESCRIPTION: Constructor for the Spreadsheet class. Based on the desired size.
     *          creates each individual cell through a loop and the class
     *          subscribe to it event
     *
     *PAREMETERS: NONE
     *POSTCONDITONS: NONE
     */
    public Spreadsheet(int rowCount, int columnCount)
    {
        RowCount = rowCount;
        ColumnCount = columnCount;

        // Initialize the 2D array of cells
        cells = new Cell[rowCount, columnCount];

        // Create cells and subscribe to PropertyChanged event
        for (int row = 0; row < rowCount; row++)
        {
            for (int col = 0; col < columnCount; col++)
            {
                cells[row, col] = new Cell(row, col);
                cells[row, col].PropertyChanged += OnCellPropertyChanged;
            }
        }
    }

    /*NAME: GET CELL
     *DESCRIPTION: Method designed to access a cell in a spreadhseet using
     *          it coordinates (row and column index)
     *
     *PAREMETERS: The Row and Column of the desired cell
     *POSTCONDITONS: It returns the cell as a Cell.
     */
    public AbstractCell GetCell(int rowIndex, int columnIndex)
    {
        if (rowIndex >= 0 && rowIndex < RowCount && columnIndex >= 0 && columnIndex < ColumnCount)
        {
            return cells[rowIndex, columnIndex];
        }

        return null;
    }

    /*NAME: UPDATE CELL VALUE
     *DESCRIPTION: Updates the value of a cell based on what the text starts with
     *
     *PAREMETERS: The desired cell that should be changed
     *POSTCONDITONS: NONE
     */
    private void UpdateCellValue(Cell cell)
    {
        if (!cell.Text.StartsWith("="))
        {
            // If the text doesn't start with '=', set value directly
            cell.Value = cell.Text;
        }
        else //update to manage 
        {
            // For simplicity, let's assume a simple formula like '=A1' where A1 is another cell

        }

        // Notify subscribers about the property change
        OnCellPropertyChanged(cell, new PropertyChangedEventArgs(cell.Text));
    }

    /*NAME: GET CELL BY NAME
    *DESCRIPTION: Function designed to find a cell referenced by it names,
                returning the named cell as a "Cell" type
    *
    *PAREMETERS: Name of target cell
    *POSTCONDITONS: Returns the referenced cell
    */
    private AbstractCell GetCellByName(string cellName)
    {
        if (Regex.IsMatch(cellName, @"^[A-Z]\d+$"))
        {
            // Extract the column letter and row number
            char columnLetter = cellName[0];
            int rowNumber = int.Parse(cellName.Substring(1));

            // Convert the column letter to a 0-based index
            int columnIndex = columnLetter - 'A';

            // Check if the row and column indices are within bounds
            if (rowNumber > 0 && columnIndex >= 0 && columnIndex < ColumnCount && rowNumber <= RowCount)
            {
                // Return the cell at the specified indices
                return GetCell(rowNumber - 1, columnIndex);
            }
        }

        return null; // Return null if the cell is not found
    }

    /*NAME: ON CELL PROPERTY CHANGED
     *DESCRIPTION: Method designed to subscribe to the change of a cell
     *
     *PAREMETERS: A sender object and a new argument for the object.
     *POSTCONDITIONS: NONE.
     */
    protected virtual void OnCellPropertyChanged(object? sender, PropertyChangedEventArgs e)
    {

        if (sender is AbstractCell cell)
        {
            if (cell.Text[0] == '=')
            {

                string expression = cell.Text.Substring(1);
                ExpressionTree tree = new ExpressionTree(expression);
                // this.ParseCellTextAndAddDependencies(cell);
                GetVariables(expression, tree);

                cell.Value = tree.Evaluate().ToString();
            }
            else
            {
                cell.Value = cell.Text;
            }

            // UpdateDependentCells(cell);
            this.SpreadsheetPropertyChanged?.Invoke(this,
                new PropertyChangedEventArgs($"Cell_{cell.RowIndex}_{cell.ColumnIndex}"));
        }

    }

    public void UpdateHelper(AbstractCell cell)
    {
        this.UpdateCellValue((Cell)cell);
    }

    private void GetVariables(string text, ExpressionTree tree)
    {
        int i = 0;
        while (i < text.Length - 1)
        {
            if (char.IsLetter(text[i]))
            {
                string cellName = (text[i].ToString() + text[i + 1].ToString());

                AbstractCell cell = GetCellByName(cellName);
                if (cell != null)
                {
                    tree.SetVariable(cellName, Convert.ToDouble(cell.Value));
                }

                i += 2; // Increment by 2 since we processed two characters
            }
            else
            {
                i++;
            }
        }
    }

    private string GetCellValue(string cellName)
    {
        if (Regex.IsMatch(cellName, @"^[A-Z]\d+$"))
        {
            // Extract the column letter and row number
            char columnLetter = cellName[0];
            int rowNumber = int.Parse(cellName.Substring(1));

            // Convert the column letter to a 0-based index
            int columnIndex = columnLetter - 'A';

            // Check if the row and column indices are within bounds
            if (rowNumber > 0 && columnIndex >= 0 && columnIndex < ColumnCount && rowNumber <= RowCount)
            {
                string check = GetCell(rowNumber - 1, columnIndex).Value;
                double doubleValue;

                if (double.TryParse(check, out doubleValue))
                {
                    // Return the cell at the specified indices
                    return GetCell(rowNumber - 1, columnIndex).Value;
                }

                else
                {
                    return "#REF";
                }
            }
        }

        return null; // Return null if the cell is not found
    }

}