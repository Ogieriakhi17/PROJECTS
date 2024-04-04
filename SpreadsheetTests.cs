using SpreadsheetEngine;

namespace SpreadsheetTests;

public class Tests
{
    [SetUp]
    public void Setup()
    {
    }

    /*NAME: GET CELL BY NAME TEST
     *DESCRIPTION: Function designed to test the Get Cell by name function
     *             it creates a small spreadsheet and call the function on
     *              a cell that exists
     *PARAMETERS: NONE
     *POSTCONDITIONS: It passes if the correct cel is found
     */
    
    /*
    [Test]
    public void GetCellByNameTest()
    {
        
        var spreadsheet = new Spreadsheet(10, 10); // Adjust the size as needed

        // Act
        var cellA1 = spreadsheet.GetCellByName("A1");

        // Assert
        Assert.IsNotNull(cellA1);
        Assert.AreEqual(0, cellA1.RowIndex);
        Assert.AreEqual(0, cellA1.ColumnIndex);
    }
    */
    
    /*NAME: GET CELL BY NAME TEST INVALID CELL NAME
     *DESCRIPTION: Function designed to test the Get Cell by name function
     *             it creates a small spreadsheet and call the function on
     *              a cell that DOES NOT exists
     *PARAMETERS: NONE
     *POSTCONDITIONS: It passes if null is returned
     */
    
    /*
    [Test]
    public void GetCellByName_InvalidCellName_ReturnsNull()
    {
        var spreadsheet = new Spreadsheet(10, 10); // Adjust the size as needed
        
        var invalidCell = spreadsheet.GetCellByName("InvalidCell");
        
        Assert.IsNull(invalidCell);
    }
    */
}