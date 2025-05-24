/**
 * @param {string} date1
 * @param {string} date2
 * @return {number}
 */
var daysBetweenDates = function(date1, date2) {
    const d1 = new Date(date1);
    const d2 = new Date(date2);

    // Calculate the difference in milliseconds
    const diffInMs = Math.abs(d1 - d2);

    // Convert milliseconds to days
    const millisecondsPerDay = 1000 * 60 * 60 * 24;
    return diffInMs / millisecondsPerDay;
};